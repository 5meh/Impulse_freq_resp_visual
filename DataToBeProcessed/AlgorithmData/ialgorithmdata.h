#ifndef IALGORITHMDATA_H
#define IALGORITHMDATA_H

#include "../idata.h"
#include <QFile>


//TODO:make separate class
struct AlgorithmMetaInfo{
    //some meta info e.g. algorithm parameters
};

template<typename Data>
class IAlgorithmData: public IData<Data, QFile, AlgorithmMetaInfo>
{
public:
    IAlgorithmData(DataSourceType sourceType,const QString& filePath, AlgorithmMetaInfo metaInfo);
    virtual const QFile& getSource()const override;
    virtual AlgorithmMetaInfo getDataMetaInfo()const override;
private:
    QFile source_;//mb should be replace with better data than file
    AlgorithmMetaInfo algMetaInfo_;
};

#endif // IALGORITHMDATA_H
