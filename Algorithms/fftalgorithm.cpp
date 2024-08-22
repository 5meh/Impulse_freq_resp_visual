#include "fftalgorithm.h"

std::vector<double> FFTAlgorithm::process(const std::vector<double>& data, bool inverse)
{
    int n = data.size();
    int logN = std::log2(n);

    // Convert input data to complex numbers
    std::vector<std::complex<double>> complexData(n);
    for (int i = 0; i < n; ++i)
    {
        complexData[i] = std::complex<double>(data[i], 0.0);
    }

    // Bit-reversal permutation
    for (int i = 0; i < n; ++i)
    {
        int j = 0;
        for (int k = 0; k < logN; ++k)
        {
            j = (j << 1) | ((i >> k) & 1);
        }
        if (i < j)
        {
            std::swap(complexData[i], complexData[j]);
        }
    }

    // FFT computation
    for (int s = 1; s <= logN; ++s)
    {
        int m = 1 << s;
        double angle = (inverse ? 2 : -2) * M_PI / m;
        std::complex<double> wm(std::cos(angle), std::sin(angle));

        for (int k = 0; k < n; k += m)
        {
            std::complex<double> w(1.0, 0.0);
            for (int j = 0; j < m / 2; ++j)
            {
                int t = k + j;
                int u = t + m / 2;
                std::complex<double> t1 = w * complexData[u];
                std::complex<double> t2 = complexData[t];

                complexData[u] = t2 - t1;
                complexData[t] = t2 + t1;

                w *= wm;
            }
        }
    }

    // Normalize if inverse FFT
    if (inverse)
    {
        for (int i = 0; i < n; ++i)
        {
            complexData[i] /= n;
        }
    }

    // Extract the real part of the complex numbers
    std::vector<double> result(n);
    for (int i = 0; i < n; ++i)
    {
        result[i] = complexData[i].real();
    }

    return result;
}
