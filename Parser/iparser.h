#ifndef IPARSER_H
#define IPARSER_H

template<typename ReturnType, typename ArgType>
class IParser
{
public:
    virtual ~IParser() = default;
    virtual ReturnType parse(const ArgType& resourceLocation) = 0;
};

#endif // IPARSER_H
