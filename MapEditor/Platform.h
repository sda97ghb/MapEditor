#ifndef PLATFORM_H
#define PLATFORM_H

#include "SFMLWidgets/ClickableConvex.h"

#include "MapEditor/Model.h"

namespace map_editor
{
    class Platform;
}

class map_editor::Platform : public sfml_widgets::ClickableConvex
{
public:
    Platform(map_editor::Model::Platform* platformModel,
             sfml_widgets::View* view);

    map_editor::Model::Platform* platformModel() const;

private:
    map_editor::Model::Platform* _platformModel;
};

#endif // PLATFORM_H
