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
        selectElement(platform);
    });
    return platform;
}

std::list<Platform>& Model::platforms()
{
    return _platforms;
}

Model::Model() :
    _currentPlatform(nullptr)
{
}

Platform* Model::currentPlatform() const
{
    return _currentPlatform;
}

Index Model::currentIndex()
{
    if (_currentPlatform == nullptr)
        return Index();
    return Index(Index::Type::platform, _currentPlatform);
}

void Model::selectElement(Platform& platform)
{
    _currentPlatform = &platform;
    notifySelected(Index(Index::Type::platform, &platform));
}

void Model::addSubsriber(ModelSubscriber& subscriber)
{
    _subsribers.push_back(&subscriber);
}

void Model::notifySelected(Index index)
{
    for (ModelSubscriber* subscriber : _subsribers)
        subscriber->elementSelected(index);
}

void Model::notifyChanged(Index index)
{
    for (ModelSubscriber* subscriber : _subsribers)
        subscriber->elementChanged(index);
}
