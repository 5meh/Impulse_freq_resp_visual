#ifndef FFTALGORITHM_H
#define FFTALGORITHM_H

#include "ialgorithm.h"
#include <vector>
#include <complex>

class FFTAlgorithm: public IAlgorithm<std::vector<double>,const std::vector<double>&, bool>
{
public:
    FFTAlgorithm() = default;
protected:
    std::vector<double> process(const std::vector<double>& data, bool inverse = false) override;
};

#endif // FFTALGORITHM_H
