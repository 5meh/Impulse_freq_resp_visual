#ifndef DATFILEPARSER_H
#define DATFILEPARSER_H
#include "fileparser.h"
#include <vector>
#include <string>
#include <QFile>

class DatFileParser: public FileParser<std::vector<std::string>, QFile>
{
public:
    ~DatFileParser();
    std::vector<std::string> parse(const QFile& file)override;
};

#endif // DATFILEPARSER_H
