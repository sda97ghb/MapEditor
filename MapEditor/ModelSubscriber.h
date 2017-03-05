#ifndef MODELSUBSCRIBER_H
#define MODELSUBSCRIBER_H

#include "MapEditor/Index.h"

class ModelSubscriber
{
public:
    virtual void elementChanged(Index index);
    virtual void elementSelected(Index index);
};

#endif // MODELSUBSCRIBER_H
