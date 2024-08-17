#include "datfilereader.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

void DatFileReader::readData(const QString& filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file for reading: " << file.errorString();
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        bool ok;
        int number = line.toInt(&ok);
        if (ok)
        {
            data.push_back(number);
        }
        else
        {
            qDebug() << "Failed to convert line to integer:" << line;
        }
    }

    file.close();
}

std::vector<int> DatFileReader::getData()
{
    return data;
}
