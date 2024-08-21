#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <memory>
#include "FileData/datfiledata.h";

class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = nullptr);
    void addDatFile(std::unique_ptr<DatFileData> datFileData);
    const std::vector<std::unique_ptr<DatFileData>>& getDatFilesData()const;
signals:

private:
    std::vector<std::unique_ptr<DatFileData>> datFilesData;

};

#endif // DATAMANAGER_H
