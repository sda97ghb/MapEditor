#include <iostream>
#include "SFMLWidgets/MovableRectangle.h"
#include "SFMLWidgets/View.h"

#include "MapEditor/Platform.h"
#include "MapEditor/PlatformDelegate.h"

map_editor::PlatformDelegate::PlatformDelegate(map_editor::Platform* platform,
                                               sfml_widgets::View* view) :
    _platform(platform),
    _view(view)
{
    for (size_t i = 0; i < platform->getPointCount(); ++i)
        addVertexButton(platform->getPoint(i), view);
}

map_editor::PlatformDelegate::~PlatformDelegate()
{
    for (sfml_widgets::MovableRectangle* vertexButton : _vertexButtons)
        _view->deleteWidget(vertexButton);
    _vertexButtons.clear();
}

void map_editor::PlatformDelegate::addVertexButton(const sf::Vector2f& position,
                                                   sfml_widgets::View* view)
{
    sfml_widgets::MovableRectangle* vertexButton =
            new sfml_widgets::MovableRectangle(view);
    _vertexButtons.push_back(vertexButton);

    vertexButton->setPosition(position + sf::Vector2f(-0.1f, -0.1f));
    vertexButton->setSize(sf::Vector2f(0.2f, 0.2f));
    vertexButton->setFillColor(sf::Color::Green);

    vertexButton->setOnGrabCallback([](){});    //fix
    vertexButton->setOnMoveCallback([](){});    //fix
    vertexButton->setOnReleaseCallback([](){}); //fix
}

map_editor::Platform* map_editor::PlatformDelegate::platform() const
{
    return _platform;
}
