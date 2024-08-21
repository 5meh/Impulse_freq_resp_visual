#ifndef FFTALGORITHM_H
#define FFTALGORITHM_H

#include "ialgorithm.h"
#include <vector>
#include <complex>

class FFTAlgorithm: public IAlgorithm<void, std::vector<std::complex<double>>&, bool>
{
public:
    FFTAlgorithm() = default;
protected:
    void process(std::vector<std::complex<double>>& data, bool inverse = false) override;
};

#endif // FFTALGORITHM_H
