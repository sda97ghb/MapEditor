#include <iostream>
#include "SFMLWidgets/MovableRectangle.h"
#include "SFMLWidgets/View.h"

#include "MapEditor/PlatformDelegate.h"
#include "MapEditor/PlatformModel.h"
#include "MapEditor/PlatformWidget.h"

map_editor::PlatformDelegate::PlatformDelegate(
        map_editor::PlatformModel* platformModel,
        PlatformWidget* platformWidget,
        sfml_widgets::View* view) :
    _platformModel(platformModel),
    _platformWidget(platformWidget),
    _view(view)
{
    for (uint32_t i = 0; i < _platformModel->vertexes().size(); ++ i)
        addVertexButton(i);

    createMovePlatformButton();
}

map_editor::PlatformDelegate::~PlatformDelegate()
{
    for (sfml_widgets::MovableRectangle* vertexButton : _vertexButtons)
        _view->deleteWidget(vertexButton);
    _vertexButtons.clear();

    _view->deleteWidget(_movePlatformButton);
}

void map_editor::PlatformDelegate::addVertexButton(int vertexNumber)
{
    sfml_widgets::MovableRectangle* vertexButton =
            new sfml_widgets::MovableRectangle(_view);
    _vertexButtons.push_back(vertexButton);

    vertexButton->setPosition(_platformModel->vertex(vertexNumber) -
                              sf::Vector2f(0.1f, 0.1f));
    vertexButton->setSize(sf::Vector2f(0.2f, 0.2f));
    vertexButton->setFillColor(sf::Color::Green);

    vertexButton->setOnGrabCallback([](){}); // fix it
    vertexButton->setOnMoveCallback([this, vertexNumber, vertexButton] () {
        sf::Vector2f vertexPos = vertexButton->getPosition() +
                sf::Vector2f(0.1f, 0.1f);
        _platformWidget->setPoint(vertexNumber, vertexPos);
    });
    vertexButton->setOnReleaseCallback(
    [this, vertexButton, vertexNumber] () {
        sf::Vector2f vertexPos = vertexButton->getPosition() +
                sf::Vector2f(0.1f, 0.1f);
        _platformModel->setVertex(vertexNumber, vertexPos);
        map_editor::Model::instance().notifyPlatformUpdated(
                    map_editor::PlatformIndex(_platformModel));
    });
}

void map_editor::PlatformDelegate::createMovePlatformButton()
{
    _movePlatformButton = new sfml_widgets::MovableRectangle(_view);

    sf::Vector2f pos(0.0f, 0.0f);
    for (uint32_t i = 0; i < _platformModel->vertexes().size(); ++ i)
        pos += _platformModel->vertex(i);
    pos *= 1.0f / static_cast<float>(_platformModel->vertexes().size());
    pos += sf::Vector2f(-0.1f, -0.1f);

    _movePlatformButton->setPosition(pos);
    _movePlatformButton->setSize(sf::Vector2f(0.2f, 0.2f));
    _movePlatformButton->setFillColor(sf::Color::Green);

    _movePlatformButton->setOnGrabCallback([&] () {
        _x0 = _movePlatformButton->getPosition().x;
        _y0 = _movePlatformButton->getPosition().y;
    });
    _movePlatformButton->setOnMoveCallback([&] () {
        sf::Vector2f d(_movePlatformButton->getPosition().x - _x0,
                       _movePlatformButton->getPosition().y - _y0);
        _platformWidget->setPosition(d);
        int i = 0;
        for (sfml_widgets::MovableRectangle* vertexButton : _vertexButtons)
        {
            vertexButton->setPosition(_platformWidget->getPoint(i++) +
                                      sf::Vector2f(-0.1f, -0.1f) + d);
        }
    });
    _movePlatformButton->setOnReleaseCallback([&] () {
        _platformWidget->setPosition(0.0f, 0.0f);
        sf::Vector2f d(_movePlatformButton->getPosition().x - _x0,
                       _movePlatformButton->getPosition().y - _y0);
        for (uint32_t i = 0; i < _platformModel->vertexes().size(); ++ i)
            _platformModel->setVertex(i, _platformModel->vertex(i) + d);

        map_editor::Model::instance().notifyPlatformUpdated(
                    map_editor::PlatformIndex(_platformModel));
    });
}

map_editor::PlatformModel* map_editor::PlatformDelegate::platformModel() const
{
    return _platformModel;
}
