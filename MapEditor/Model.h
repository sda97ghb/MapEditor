#ifndef MAP_EDITOR_MODEL_H
#define MAP_EDITOR_MODEL_H

#include <list>

#include "SFML/System/Vector2.hpp"

#include "MapEditor/Index.h"
#include "MapEditor/PlatformModel.h"

namespace map_editor
{
    class Model;
    class ModelSubscriber;
}

class map_editor::Model
{
public:
    static Model& instance();

    void drop();

    map_editor::PlatformModel& createPlatform();
    void deletePlatform(map_editor::PlatformModel& platform);
    std::list<map_editor::PlatformModel>& platforms();
    void notifyPlatformAdded(const map_editor::Index& platformIndex);
    void notifyPlatformDeleted(const map_editor::Index& platformIndex);
    void notifyPlatformUpdated(const map_editor::Index& platformIndex);

    void selectIndex(const map_editor::Index& index);
    void notifyIndexSelected();

    void deleteCurrentIndex();

    void addSubscriber(map_editor::ModelSubscriber* subscriber);

private:
    Model() = default;

    Model(const Model& model) = delete;
    void operator= (const Model& model) = delete;

    map_editor::Index _currentIndex;

    std::list<map_editor::PlatformModel> _platforms;

    std::list<map_editor::ModelSubscriber*> _subscribers;
};

#endif // MAP_EDITOR_MODEL_H
