#include "datamanager.h"
#include "idata.h"
#include "FileData/datfiledata.h"

DataManager::DataManager(QObject *parent)
    : QObject{parent}
{

}

void DataManager::addDatFile(std::unique_ptr<DatFileData> datFileData)
{
    datFilesData.push_back(std::move(datFileData));
}

const std::vector<std::unique_ptr<DatFileData>>& DataManager::getDatFilesData()const
{
    return datFilesData;
}
