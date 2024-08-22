#include "fftalgorithmdata.h"

FFTalgorithmData::FFTalgorithmData(DataSourceType sourceType, const QString& filePath, std::vector<double> data, AlgorithmMetaInfo algMetaInfo):
    IAlgorithmData<std::vector<double>>(sourceType, filePath,algMetaInfo),
    data_(data)
{

}

std::vector<double> FFTalgorithmData::getData()const
{
    return data_;
}
