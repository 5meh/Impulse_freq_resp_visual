#ifndef ALGORITHMTEMPLATE_H
#define ALGORITHMTEMPLATE_H

template<typename RetType, typename... Args>
class AlgorithmTemplate
{
public:
    virtual ~AlgorithmTemplate() = default;
    RetType execute(Args... args) {
        return process(args);
    }
protected:
    virtual RetType process(Args... args) = 0;
};

#endif // ALGORITHMTEMPLATE_H
