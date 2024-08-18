#ifndef DATFILEDATA_H
#define DATFILEDATA_H

#include "filedata.h"
#include <vector>

class DatFileData: public FileData<std::vector<int>>
{
public:
    DatFileData(DataSourceType sourceType, QString& filePath, std::vector<int> data);
    std::vector<int> getData()const override;
private:
    std::vector<int> data_;
};

#endif // DATFILEDATA_H
