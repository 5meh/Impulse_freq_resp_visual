#ifndef IDATA_H
#define IDATA_H

#include "datasourcetype.h"

template<typename Data, typename Source, typename MetaInfo>//TODO: mb unite data, source, dataMetaInfo under one class?
class IData
{
public:
    IData(DataSourceType dataSourceType):dataSourceType_(dataSourceType){}
    virtual ~IData() = default;

    DataSourceType getSourceType()const{ return dataSourceType_; }
    virtual Data getData()const = 0;
    virtual const Source& getSource()const = 0;
    virtual MetaInfo getDataMetaInfo()const = 0;
private:
    DataSourceType dataSourceType_;
};

#endif // IDATA_H
