#ifndef PLATFORM_H
#define PLATFORM_H

#include "SFMLWidgets/ClickableConvex.h"

#include "MapEditor/Model.h"

namespace map_editor
{
    class PlatformWidget;
}

class map_editor::PlatformWidget : public sfml_widgets::ClickableConvex
{
public:
    PlatformWidget(map_editor::PlatformModel* platformModel,
             sfml_widgets::View* view);

    map_editor::PlatformModel* platformModel() const;

private:
    map_editor::PlatformModel* _platformModel;
};

#endif // PLATFORM_H
