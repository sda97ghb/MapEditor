#include "MapEditor/PlatformWidget.h"

map_editor::PlatformWidget::PlatformWidget(PlatformModel* platformModel,
                               sfml_widgets::View* view) :
    sfml_widgets::ClickableConvex(view),
    _platformModel(platformModel)
{
}

map_editor::PlatformModel* map_editor::PlatformWidget::platformModel() const
{
    return _platformModel;
}
