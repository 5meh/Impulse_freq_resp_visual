#include "datamanager.h"
#include "idata.h"
#include "FileData/datfiledata.h"

DataManager::DataManager(QObject *parent)
    : QObject{parent}
{

}

void DataManager::addDatFile(std::unique_ptr<DatFileData> datFileData)
{
    datFilesData_.push_back(std::move(datFileData));
}

void DataManager::addAlgorithmResults(std::unique_ptr<FFTalgorithmData> algResData)
{
    fftAlgRes_.push_back(std::move(algResData));
}

const std::vector<std::unique_ptr<DatFileData>>& DataManager::getDatFilesData()const
{
    return datFilesData_;
}

 const std::vector<std::unique_ptr<FFTalgorithmData>>& DataManager::getFFTAlgorithmResults()const
 {
    return fftAlgRes_;
 }
