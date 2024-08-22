#ifndef IALGORITHM_H
#define IALGORITHM_H

const double PI = 3.141592653589793238460;

template<typename RetType, typename... Args>
class IAlgorithm
{
public:
    virtual ~IAlgorithm() = default;
    RetType execute(Args... args)
    {
        return process(args...);
    }
protected:
    virtual RetType process(Args... args) = 0;
};

#endif // IALGORITHM_H
