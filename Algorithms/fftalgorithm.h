#ifndef FFTALGORITHM_H
#define FFTALGORITHM_H

#include "ialgorithm.h"
#include <vector>
#include <complex>

//TODO:rename class
class FFTAlgorithm: public IAlgorithm<std::vector<double>,const std::vector<double>&, bool>
{
public:
    FFTAlgorithm() = default;
protected:
    std::vector<double> process(const std::vector<double>& measurements, bool inverse = false) override;
    std::vector<double> calculateAmplitudeSpectrum(const std::vector<std::complex<double>>& data);
    std::vector<double> calculateEnvelope(const std::vector<double>& spectrum);
    void iterativeFFT(std::vector<std::complex<double>>& data);
};

#endif // FFTALGORITHM_H
