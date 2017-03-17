#ifndef PLATFORMDELEGATE_H
#define PLATFORMDELEGATE_H

#include <list>

#include "SFML/System/Vector2.hpp"

namespace sfml_widgets
{
    class MovableRectangle;
    class View;
}

namespace map_editor
{
    class PlatformDelegate;
    class PlatformModel;
    class PlatformWidget;
}

class map_editor::PlatformDelegate
{
public:
    PlatformDelegate(map_editor::PlatformModel* platformModel,
                     map_editor::PlatformWidget* platformWidget,
                     sfml_widgets::View* view);
    ~PlatformDelegate();

    map_editor::PlatformModel* platformModel() const;

private:
    void addVertexButton(int vertexNumber);
    void createMovePlatformButton();

    map_editor::PlatformModel* _platformModel;
    map_editor::PlatformWidget* _platformWidget;

    sfml_widgets::View* _view;

    std::list<sfml_widgets::MovableRectangle*> _vertexButtons;

    sfml_widgets::MovableRectangle* _movePlatformButton;

    float _x0;
    float _y0;
};

#endif // PLATFORMDELEGATE_H
