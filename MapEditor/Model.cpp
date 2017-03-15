#include <algorithm>
#include <iostream>

#include "MapEditor/Model.h"

//-------- Model --------//

map_editor::Model& map_editor::Model::instance()
{
    static Model instance;
    return instance;
}

map_editor::Model::Platform& map_editor::Model::createPlatform()
{
    _platforms.emplace_back();
    notifyPlatformAdded(map_editor::Index(map_editor::Index::Type::platform,
                                          &_platforms.back()));
    return _platforms.back();
}

void map_editor::Model::deletePlatform(map_editor::Model::Platform& platform)
{
    map_editor::Model::Platform* platformPtr = &platform;

    auto platformIter = std::find_if(_platforms.begin(), _platforms.end(),
    [&] (const map_editor::Model::Platform& platformI) {
        return &platformI == platformPtr;
    });
    if (platformIter == _platforms.end())
        return;
    auto platformIterEnd = platformIter;
    std::advance(platformIterEnd, 1);
    _platforms.erase(platformIter, platformIterEnd);

    notifyPlatformDeleted(map_editor::Index(map_editor::Index::Type::platform,
                                            platformPtr));
}

std::list<map_editor::Model::Platform>& map_editor::Model::platforms()
{
    return _platforms;
}

void map_editor::Model::notifyPlatformAdded(
        const map_editor::Index& platformIndex)
{
    for (map_editor::ModelSubscriber* subscriber : _subscribers)
        subscriber->platformAdded(platformIndex);
}

void map_editor::Model::notifyPlatformDeleted(
        const map_editor::Index& platformIndex)
{
    for (map_editor::ModelSubscriber* subscriber : _subscribers)
        subscriber->platformDeleted(platformIndex);
}

void map_editor::Model::notifyPlatformUpdated(
        const map_editor::Index& platformIndex)
{
    for (map_editor::ModelSubscriber* subscriber : _subscribers)
        subscriber->platformUpdated(platformIndex);
}

void map_editor::Model::selectIndex(const map_editor::Index& index)
{
    _currentIndex = index;
    notifyIndexSelected();
}

void map_editor::Model::notifyIndexSelected()
{
    for (map_editor::ModelSubscriber* subscriber : _subscribers)
        subscriber->indexSelected(_currentIndex);
}

void map_editor::Model::deleteCurrentIndex()
{
    switch (_currentIndex.type())
    {
        case map_editor::Index::Type::undefined :
            return;
        case map_editor::Index::Type::platform :
            deletePlatform(*static_cast<map_editor::Model::Platform*>(_currentIndex.object()));
        break;
    }
    _currentIndex.set(map_editor::Index::Type::undefined, nullptr);
}

void map_editor::Model::addSubscriber(map_editor::ModelSubscriber* subscriber)
{
    _subscribers.push_back(subscriber);
}

//-------- Model::Platform --------//

map_editor::Model::Platform::Platform()
{
    std::cout << "Model platform constructor" << std::endl;
}

map_editor::Model::Platform::~Platform()
{
    std::cout << "Model platform destructor" << std::endl;
}

void map_editor::Model::Platform::setVertexes(
        const std::list<sf::Vector2f>& vertexes)
{
    _vertexes = vertexes;
    Model::instance().notifyPlatformUpdated(
                map_editor::Index(map_editor::Index::Type::platform,
                                  this));
}

const std::list<sf::Vector2f>& map_editor::Model::Platform::vertexes() const
{
    return _vertexes;
}
