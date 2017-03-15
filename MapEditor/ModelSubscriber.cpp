#include "MapEditor/Model.h"
#include "MapEditor/ModelSubscriber.h"

map_editor::ModelSubscriber::ModelSubscriber()
{
    Model::instance().addSubscriber(this);
}

void map_editor::ModelSubscriber::platformAdded(const map_editor::Index& index)
{
    (void)index;
}

void map_editor::ModelSubscriber::platformDeleted(const map_editor::Index& index)
{
    (void)index;
}

void map_editor::ModelSubscriber::platformUpdated(const map_editor::Index& index)
{
    (void)index;
}

void map_editor::ModelSubscriber::indexSelected(const map_editor::Index& index)
{
    (void)index;
}
