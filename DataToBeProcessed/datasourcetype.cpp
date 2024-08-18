#include "datasourcetype.h"

DataSourceType::DataSourceType(SourceType type)
{
    dataSourceType=type;
}

DataSourceType::SourceType DataSourceType::getDataSourceType()const
{
    return dataSourceType;
}

std::string DataSourceType::getDataSourceTypeAsString()const
{
    switch (dataSourceType)
    {
    case SourceType::File: return "File";
    case SourceType::Database: return "Database";
    case SourceType::API: return "API";
    case SourceType::Stream: return "Stream";
    default: return "Unknown";
    }
}
