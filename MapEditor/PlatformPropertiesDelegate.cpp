#include "PlatformPropertiesDelegate.h"

#include "SFMLWidgets/Button.h"
#include "SFMLWidgets/View.h"

#include "MapEditor/Model.h"
#include "MapEditor/PlatformModel.h"

map_editor::PlatformPropertiesDelegate::PlatformPropertiesDelegate(
        map_editor::PlatformModel* platform, sfml_widgets::View* view) :
    _view(view),
    _platformModel(platform)
{
    _addVertexButton = new sfml_widgets::Button(_view);
    _deleteVertexButton = new sfml_widgets::Button(_view);

    _addVertexButton->setFillColor(sf::Color::Green);
    _addVertexButton->setSize(sf::Vector2f(100.0f, 30.0f));
    _addVertexButton->setPosition(20.0f, 40.0f);
    _addVertexButton->setText("Add vertex");

    _deleteVertexButton->setFillColor(sf::Color::Red);
    _deleteVertexButton->setSize(sf::Vector2f(100.0f, 30.0f));
    _deleteVertexButton->setPosition(20.0f, 80.0f);
    _deleteVertexButton->setText("Delete vertex");

    _addVertexButton->setOnClickCallback([&](){
        std::vector<sf::Vector2f> vertexes = _platformModel->vertexes();
        vertexes.emplace_back(vertexes.back() + sf::Vector2f(0.5f, 0.5f));
        _platformModel->setVertexes(vertexes);
        map_editor::Model::instance().notifyPlatformUpdated(
                    map_editor::PlatformIndex(_platformModel));
    });
    _deleteVertexButton->setOnClickCallback([&](){
        std::vector<sf::Vector2f> vertexes = _platformModel->vertexes();
        vertexes.erase(--(vertexes.end()));
        _platformModel->setVertexes(vertexes);
        map_editor::Model::instance().notifyPlatformUpdated(
                    map_editor::PlatformIndex(_platformModel));
    });
}

map_editor::PlatformPropertiesDelegate::~PlatformPropertiesDelegate()
{
    _view->deleteWidget(_addVertexButton);
    _view->deleteWidget(_deleteVertexButton);
}

map_editor::PlatformModel* map_editor::PlatformPropertiesDelegate::platformModel() const
{
    return _platformModel;
}
