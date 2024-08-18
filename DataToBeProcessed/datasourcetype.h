#ifndef DATASOURCETYPE_H
#define DATASOURCETYPE_H

#include <string>

class DataSourceType
{
private:
    enum class SourceType {
        File,
        Database,
        API,
        Stream
    };
public:
    DataSourceType(SourceType type);
    SourceType getDataSourceType()const;
    std::string getDataSourceTypeAsString()const;
    ~DataSourceType() = default;

private:
    SourceType dataSourceType;
};

#endif // DATASOURCETYPE_H
