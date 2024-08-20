#include "datfiledata.h"

DatFileData::DatFileData(DataSourceType sourceType, QString& filePath, std::vector<double> data):
    FileData(sourceType, filePath),
    data_(data)
{

}

std::vector<double> DatFileData::getData()const
{
    return data_;
}
