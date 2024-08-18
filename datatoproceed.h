#ifndef DATATOPROCEED_H
#define DATATOPROCEED_H
#include <QFile>
#include <vector>

class DataToProceed
{
public:
    DataToProceed();
private:
    std::vector<QFile*> associatedFiles;//TODO::mb replace with just QFile?

};

#endif // DATATOPROCEED_H
