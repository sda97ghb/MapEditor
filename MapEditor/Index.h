#ifndef INDEX_H
#define INDEX_H

#include "MapEditor/Properted.h"

class Index
{
public:
    enum class Type
    {
        null,
        platform
    };

    Index() :
        type(Type::null),
        object(nullptr)
    {}

    Index(Type type_, Properted* object_) :
        type(type_),
        object(object_)
    {}

    Type type;

    Properted* object;
};

#endif // INDEX_H
