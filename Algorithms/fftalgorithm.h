#ifndef FFTALGORITHM_H
#define FFTALGORITHM_H

#include "ialgorithm.h"\
#include <vector>

class FFTAlgorithm: public IAlgorithm<std::vector<double>, std::vector<double>>
{
public:
    FFTAlgorithm() = default;
protected:
    void process(std::vector<std::complex<double>>& data, bool inverse = false) override;
};

#endif // FFTALGORITHM_H
