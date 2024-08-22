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
    const std::vector<std::unique_ptr<DatFileData>>& getDatFilesData()const;
signals:

private:
    std::vector<std::unique_ptr<DatFileData>> datFilesData_;
    std::vector<std::unique_ptr<FFTalgorithmData>> datFilesAlgRes_;


};

#endif // DATAMANAGER_H
