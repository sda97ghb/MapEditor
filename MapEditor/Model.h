#ifndef MAP_EDITOR_MODEL_H
#define MAP_EDITOR_MODEL_H

#include <list>

#include "SFML/System/Vector2.hpp"

#include "MapEditor/Index.h"
#include "MapEditor/ModelSubscriber.h"

namespace map_editor
{
    class Model;
}

class map_editor::Model
{
public:
    class Platform;

    static Model& instance();

    Platform& createPlatform();
    std::list<map_editor::Model::Platform>& platforms();
    void notifyPlatformAdded(const map_editor::Index& platformIndex);
    void notifyPlatformDeleted(const map_editor::Index& platformIndex);
    void notifyPlatformUpdated(const map_editor::Index& platformIndex);

    void selectIndex(const map_editor::Index& index);
    void notifyIndexSelected();

    void deleteCurrentIndex();

    void deletePlatform(map_editor::Model::Platform* platform);

    void addSubscriber(map_editor::ModelSubscriber* subscriber);

private:
    Model() = default;

    Model(const Model& model) = delete;
    void operator= (const Model& model) = delete;

    map_editor::Index _currentIndex;

    std::list<map_editor::Model::Platform> _platforms;

    std::list<map_editor::ModelSubscriber*> _subscribers;
};

class map_editor::Model::Platform : public map_editor::Indexed
{
public:
    void setVertexes(const std::list<sf::Vector2f>& vertexes);
    const std::list<sf::Vector2f>& vertexes() const;

private:
    std::list<sf::Vector2f> _vertexes;
};

#endif // MAP_EDITOR_MODEL_H
