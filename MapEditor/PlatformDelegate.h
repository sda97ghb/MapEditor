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
    class Platform;
    class PlatformDelegate;
}

class map_editor::PlatformDelegate
{
public:
    PlatformDelegate(map_editor::Platform* platform,
                     sfml_widgets::View* view);
    ~PlatformDelegate();

    map_editor::Platform* platform() const;

private:
    void addVertexButton(const sf::Vector2f& position, int vertexNumber,
                         sfml_widgets::View* view);

    std::list<sfml_widgets::MovableRectangle*> _vertexButtons;

    map_editor::Platform* _platform;
    sfml_widgets::View* _view;
};

#endif // PLATFORMDELEGATE_H
