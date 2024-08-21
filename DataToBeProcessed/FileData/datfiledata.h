#ifndef DATFILEDATA_H
#define DATFILEDATA_H

#include "filedata.h"
#include <vector>

class DatFileData: public FileData<std::vector<double>>
{
public:
    DatFileData(DataSourceType sourceType, QString& filePath, std::vector<double> data);
    std::vector<double> getData()const override;
private:
    std::vector<double> data_;
};

#endif // DATFILEDATA_H
