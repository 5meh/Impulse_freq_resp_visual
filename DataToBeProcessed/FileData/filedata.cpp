#include "filedata.h"

template<typename Data>
FileData<Data>::FileData(DataSourceType sourceType, QString& filePath):
    IData<Data, QFile, QFileInfo>(sourceType),
    file_(filePath),
    fileMetaInfo_(file_)
{

}

template<typename Data>
const QFile& FileData<Data>::getSource()const
{
    return file_;
}

template<typename Data>
QFileInfo FileData<Data>::getDataMetaInfo()const
{
    return fileMetaInfo_;
}

template class FileData<std::vector<int>>;
