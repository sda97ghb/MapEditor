#ifndef PLATFORMPROPERTIESDELEGATE_H
#define PLATFORMPROPERTIESDELEGATE_H

#include "SFML/Graphics/Font.hpp"

namespace sfml_widgets
{
    class Button;
    class View;
}

namespace map_editor
{
    class PlatformModel;
    class PlatformPropertiesDelegate;
}

class map_editor::PlatformPropertiesDelegate
{
public:
    PlatformPropertiesDelegate(map_editor::PlatformModel* platformModel,
                               sfml_widgets::View* view);
    ~PlatformPropertiesDelegate();

    map_editor::PlatformModel* platformModel() const;

private:
    sfml_widgets::View* _view;

    sfml_widgets::Button* _addVertexButton;
    sfml_widgets::Button* _deleteVertexButton;

    map_editor::PlatformModel* _platformModel;
};

#endif // PLATFORMPROPERTIESDELEGATE_H
