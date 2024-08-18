#ifndef DATFILEREADER_H
#define DATFILEREADER_H
#include "filereader.h"

class DatFileReader: public FileReader<int>
{
public:
    void readData(const QString& filePath);
    std::vector<int> getData()const;
private:
    std::vector<int> data;
};

#endif // DATFILEREADER_H
