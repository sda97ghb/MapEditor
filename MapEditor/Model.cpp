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

Model::Model()
{
}

Index Model::currentIndex()
{
    return _currentIndex;
}

void Model::selectElement(Platform& platform)
{
    _currentIndex = Index(Index::Type::platform, &platform);
    notifySelected(_currentIndex);
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
