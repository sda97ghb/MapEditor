#ifndef MODEL_H
#define MODEL_H

#include "MapEditor/Platform.h"

class Model
{
public:
    static Model& instance();

    Platform& createPlatform();

    std::list<Platform>& platforms();

private:
    Model() = default;

    Model(const Model& model) = delete;
    void operator= (const Model& model) = delete;

    std::list<Platform> _platforms;
};

#endif // MODEL_H
