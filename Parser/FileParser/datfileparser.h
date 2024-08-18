#ifndef DATFILEPARSER_H
#define DATFILEPARSER_H
#include "fileparser.h"
#include <vector>
#include <string>
#include <QFile>

class DatFileParser: public FileParser<std::vector<int>>
{
public:
    ~DatFileParser() = default;
    std::vector<int> parse(const QString& fullFilePath)override;
};

#endif // DATFILEPARSER_H
