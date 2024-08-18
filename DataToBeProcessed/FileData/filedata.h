#ifndef FILEDATA_H
#define FILEDATA_H
#include "../idata.h"
#include <QFile>
#include <QFileInfo>

template<typename Data>
class FileData: public IData<Data, QFile, QFileInfo>
{
public:
    FileData(DataSourceType sourceType, QString& filePath);
    const QFile& getSource()const override;
    QFileInfo getDataMetaInfo()const override;
private:
    QFile file_;
    QFileInfo fileMetaInfo_;
};

#endif // FILEDATA_H
