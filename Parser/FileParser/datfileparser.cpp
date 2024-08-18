#include "datfileparser.h"

DatFileParser::DatFileParser()
{

}

std::vector<std::string> DatFileParser::parse(const QFile& file)
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        return;
    }
    QTextStream in(&file);
    bool isFirstLine = true;

    std::vector<std::string> parsedData;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (isFirstLine)
        {
            isFirstLine = false;
            continue;
        }
        parsedData.push_back(line);
        qDebug() << line;
    }

    file.close();
}
