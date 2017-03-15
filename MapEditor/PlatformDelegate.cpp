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
        addVertexButton(platform->getPoint(i), i, view);
}

map_editor::PlatformDelegate::~PlatformDelegate()
{
    for (sfml_widgets::MovableRectangle* vertexButton : _vertexButtons)
        _view->deleteWidget(vertexButton);
    _vertexButtons.clear();
}

void map_editor::PlatformDelegate::addVertexButton(const sf::Vector2f& position,
                                                   int vertexNumber,
                                                   sfml_widgets::View* view)
{
    sfml_widgets::MovableRectangle* vertexButton =
            new sfml_widgets::MovableRectangle(view);
    _vertexButtons.push_back(vertexButton);

    vertexButton->setPosition(position + sf::Vector2f(-0.1f, -0.1f));
    vertexButton->setSize(sf::Vector2f(0.2f, 0.2f));
    vertexButton->setFillColor(sf::Color::Green);

    vertexButton->setOnGrabCallback([](){
        std::cout << "grab" << std::endl;
    });    //fix
    vertexButton->setOnMoveCallback(
    [this, vertexNumber, vertexButton] () {
        sf::Vector2f vertexPos = vertexButton->getPosition() +
                sf::Vector2f(0.1f, 0.1f);
        _platform->setPoint(vertexNumber, vertexPos);
    });
    vertexButton->setOnReleaseCallback([this, vertexButton, vertexNumber] () {
        std::cout << "release" << std::endl;
        sf::Vector2f vertexPos = vertexButton->getPosition() +
                sf::Vector2f(0.1f, 0.1f);
        std::list<sf::Vector2f> vertexes = _platform->platformModel()->vertexes();
        auto vertexIter = vertexes.begin();
        std::advance(vertexIter, vertexNumber);
        (*vertexIter) = vertexPos;
        _platform->platformModel()->setVertexes(vertexes);
        map_editor::Model::instance().notifyPlatformUpdated(
                    map_editor::Index(map_editor::Index::Type::platform,
                                      _platform->platformModel()));
    });
}

map_editor::Platform* map_editor::PlatformDelegate::platform() const
{
    return _platform;
}
