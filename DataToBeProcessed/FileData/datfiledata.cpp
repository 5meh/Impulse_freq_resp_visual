#include "datfiledata.h"

DatFileData::DatFileData(DataSourceType sourceType, QString& filePath, std::vector<int> data):
    FileData(sourceType, filePath),
    data_(data)
{

}

std::vector<int> DatFileData::getData()const
{
    return data_;
}
