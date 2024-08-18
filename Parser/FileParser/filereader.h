#ifndef FILEREADER_H
#define FILEREADER_H

//#include <string>
#include <vector>
#include <QString>

template<typename T>
class FileReader
{
public:
    virtual void readData(const QString& filePath) = 0;
    virtual std::vector<T> getData()const = 0;
    virtual ~FileReader() = default;
};

#endif // FILEREADER_H
