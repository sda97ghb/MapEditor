#include "MapEditor/Platform.h"

map_editor::Platform::Platform(map_editor::Model::Platform* platformModel,
                               sfml_widgets::View* view) :
    sfml_widgets::ClickableConvex(view),
    _platformModel(platformModel)
{
}

map_editor::Model::Platform* map_editor::Platform::platformModel() const
{
    return _platformModel;
}
