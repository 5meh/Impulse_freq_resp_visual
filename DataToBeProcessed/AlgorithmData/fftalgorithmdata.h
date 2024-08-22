#ifndef FFTALGORITHMDATA_H
#define FFTALGORITHMDATA_H

#include "ialgorithmdata.h"

class FFTalgorithmData: public IAlgorithmData<std::vector<double>>
{
public:
    FFTalgorithmData(DataSourceType sourceType, QString& filePath, std::vector<double> data, AlgorithmMetaInfo algMetaInfo);
    std::vector<double> getData()const override;
private:
    std::vector<double> data_;
};

#endif // FFTALGORITHMDATA_H
