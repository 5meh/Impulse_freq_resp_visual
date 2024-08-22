#include "fftalgorithm.h"

std::vector<double> FFTAlgorithm::process(const std::vector<double>& measurements, bool inverse)
{
    int sampleRate = 106;//TODO:get from algorithm metadata, magic numbers - not comme il faut

    std::vector<std::complex<double>> data(measurements.begin(), measurements.end());

    iterativeFFT(data);

    std::vector<double> spectrum = calculateAmplitudeSpectrum(data);
    std::vector<double> envelope = calculateEnvelope(spectrum);
    return envelope;
}

std::vector<double> FFTAlgorithm::calculateAmplitudeSpectrum(const std::vector<std::complex<double>>& data)
{
    std::vector<double> amplitudeSpectrum(data.size() / 2);
    for (size_t i = 0; i < amplitudeSpectrum.size(); ++i)
    {
        amplitudeSpectrum[i] = std::abs(data[i]);
    }
    return amplitudeSpectrum;
}

std::vector<double> FFTAlgorithm::calculateEnvelope(const std::vector<double>& spectrum)
{
    std::vector<double> envelope(spectrum.size());
    for (size_t i = 1; i < spectrum.size() - 1; ++i) {
        if (spectrum[i] > spectrum[i - 1] && spectrum[i] > spectrum[i + 1]) {
            envelope[i] = spectrum[i];
        } else {
            envelope[i] = (spectrum[i - 1] + spectrum[i + 1]) / 2.0;
        }
    }
    envelope[0] = spectrum[0];
    envelope[spectrum.size() - 1] = spectrum[spectrum.size() - 1];
    return envelope;
}

void FFTAlgorithm::iterativeFFT(std::vector<std::complex<double>>& data)
{
    int n = data.size();
    int logN = log2(n);

    // bit permutation
    for (int i = 1, j = 0; i < n; ++i)
    {
        int bit = n >> 1;
        while (j >= bit)
        {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j)
        {
            std::swap(data[i], data[j]);
        }
    }

    // FTP loop
    for (int len = 2; len <= n; len <<= 1)
    {
        double angle = -2 * M_PI / len;
        std::complex<double> wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len)
        {
            std::complex<double> w(1);
            for (int j = 0; j < len / 2; ++j)
            {
                std::complex<double> u = data[i + j];
                std::complex<double> v = data[i + j + len / 2] * w;
                data[i + j] = u + v;
                data[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
}
