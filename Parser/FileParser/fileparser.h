#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "../iparser.h"
#include <QFile>

template<typename ReturnType>
class FileParser: public IParser<ReturnType, QFile>
{
public:
    ~FileParser() = default;
    virtual ReturnType parse(const QFile& file) = 0;

};

#endif // FILEPARSER_H
