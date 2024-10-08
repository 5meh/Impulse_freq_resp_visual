#include "datfileparser.h"
#include <QDebug>

std::vector<double> DatFileParser::parse(const QString& fullFilePath)
{
    QFile file(fullFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        //return;//TODO: add error processing
    }
    QTextStream in(&file);
    bool isFirstLine = true;

    std::vector<double> parsedData;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (isFirstLine)
        {
            isFirstLine = false;
            continue;
        }
        parsedData.push_back(line.toDouble());
        qDebug() << line;
    }

    file.close();
    return parsedData;
}
