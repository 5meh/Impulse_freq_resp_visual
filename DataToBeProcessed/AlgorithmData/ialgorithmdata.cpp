#include "ialgorithmdata.h"

template<typename Data>
IAlgorithmData<Data>::IAlgorithmData(DataSourceType sourceType, const QString& filePath, AlgorithmMetaInfo metaInfo):
    IData<Data, QFile, AlgorithmMetaInfo>(sourceType),
    source_(filePath),
    algMetaInfo_(metaInfo)

{

}

template<typename Data>
const QFile& IAlgorithmData<Data>::getSource()const
{
    return source_;
}

template<typename Data>
AlgorithmMetaInfo IAlgorithmData<Data>::getDataMetaInfo()const
{
    return algMetaInfo_;
}

template class IAlgorithmData<std::vector<double>>;
