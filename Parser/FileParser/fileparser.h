#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "../iparser.h"
#include <QFile>

template<typename ReturnType>
class FileParser: public IParser<ReturnType, QString>
{
public:
    ~FileParser() = default;
    virtual ReturnType parse(const QString& fullFilePath) = 0;

};

#endif // FILEPARSER_H
