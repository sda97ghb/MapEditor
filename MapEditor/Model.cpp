#include "Model.h"

Model& Model::instance()
{
    static Model instance;
    return instance;
}

Platform& Model::createPlatform()
{
    _platforms.emplace_back();
    Platform& platform = _platforms.back();

    platform.setOnClickCallback([this, &platform] () {
        setCurrentPlatform(platform);
    });
    return platform;
}

std::list<Platform>& Model::platforms()
{
    return _platforms;
}

void Model::setCurrentPlatform(Platform& platform)
{
    _currentPlatform = &platform;
}

Model::Model() :
    _currentPlatform(nullptr)
{
}

Platform* Model::currentPlatform() const
{
    return _currentPlatform;
}

Model::Index Model::currentIndex()
{
    if (_currentPlatform == nullptr)
        return Index::zero();
    return Index(Index::Type::platform, _currentPlatform);
}
