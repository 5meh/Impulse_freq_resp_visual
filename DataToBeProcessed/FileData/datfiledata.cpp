#include "datfiledata.h"

DatFileData::DatFileData(DataSourceType sourceType, QFile& file, std::vector<int> data):FileData(sourceType, file),data_(data)
{

}

std::vector<int> DatFileData::getData()const
{
    return data_;
}
