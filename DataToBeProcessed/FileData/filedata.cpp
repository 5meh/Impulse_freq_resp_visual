#include "filedata.h"

template<typename Data>
FileData<Data>::FileData(DataSourceType sourceType, QFile& file):
    IData<Data, QFile, QFileInfo>(sourceType),
    file_(file.fileName()),
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
