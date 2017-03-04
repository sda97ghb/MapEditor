#include "Model.h"

Model& Model::instance()
{
    static Model instance;
    return instance;
}

Platform& Model::createPlatform()
{
    _platforms.emplace_back();
    return _platforms.back();
}

std::list<Platform>& Model::platforms()
{
    return _platforms;
}
