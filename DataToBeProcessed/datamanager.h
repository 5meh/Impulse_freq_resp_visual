#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <memory>
//#include "idatamanager.h"
#include "FileData/datfiledata.h";
#include "AlgorithmData/fftalgorithmdata.h"

class DataManager: public QObject //: public IDataManager
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = nullptr);
    void addDatFile(std::unique_ptr<DatFileData> datFileData);
    void addAlgorithmResults(std::unique_ptr<FFTalgorithmData> algResData);

    const std::vector<std::unique_ptr<DatFileData>>& getDatFilesData()const;
    const std::vector<std::unique_ptr<FFTalgorithmData>>& getFFTAlgorithmResults()const;

signals:

private:
    std::vector<std::unique_ptr<DatFileData>> datFilesData_;
    std::vector<std::unique_ptr<FFTalgorithmData>> fftAlgRes_;


};

#endif // DATAMANAGER_H
