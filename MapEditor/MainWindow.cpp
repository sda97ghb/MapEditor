#include <iostream>

#include "MapEditor/MainWindow.h"
#include "MapEditor/Model.h"

map_editor::MainWindow::MainWindow() :
    sfml_widgets::Window(1500, 800, "SFMLWidgets test", sf::Style::Default),
    _platformDelegate(nullptr)
{
//    setClearColor(sf::Color(64, 192, 255));
    setClearColor(sf::Color(30, 30, 30));

    _panelView = new sfml_widgets::View(this);
    _toolbarView = new sfml_widgets::View(this);
    _worldView = new sfml_widgets::View(this);

    _panelView->setViewport(sf::FloatRect(0.8f, 0.1f, 0.2f, 0.9f));
    _panelView->setSize(300.0f, 700.0f);
    _panelView->setCenter(150.0f, 350.0f);

    _toolbarView->setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 0.1f));
    _toolbarView->setSize(1500.0f, 80.0f);
    _toolbarView->setCenter(750.0f, 40.0f);

    _worldView->setViewport(sf::FloatRect(0.0f, 0.1f, 0.8f, 0.9f));
    _worldView->setSize(36.0f, -21.0f);
    _worldView->setCenter(0.0f, 0.0f);

    _panelSplitter = new sfml_widgets::RectangleWidget(_panelView);
    _panelSplitter->setFillColor(sf::Color(120, 120, 120));
    _panelSplitter->setPosition(0.0f, 0.0f);
    _panelSplitter->setSize(sf::Vector2f(2.0f, _panelView->getSize().y));

    _panelSplitter = new sfml_widgets::RectangleWidget(_toolbarView);
    _panelSplitter->setFillColor(sf::Color(120, 120, 120));
    _panelSplitter->setPosition(0.0f, _toolbarView->getSize().y - 2.0f);
    _panelSplitter->setSize(sf::Vector2f(_toolbarView->getSize().x, 2.0f));

    constructToolbar();
}

void map_editor::MainWindow::constructToolbar()
{
    _addPlatformButton = new sfml_widgets::Button(_toolbarView);
    _addPlatformButton->setPosition(10.0f, 10.0f);
    _addPlatformButton->setSize(sf::Vector2f(60.0f, 60.0f));
    _addPlatformButton->setFillColor(sf::Color(100, 100, 100));
    _addPlatformButton->setOnClickCallback([=] () {
        map_editor::Model::Platform& platform =
                map_editor::Model::instance().createPlatform();

        std::list<sf::Vector2f> vertexes;
        vertexes.emplace_back(-1.0f, -1.0f);
        vertexes.emplace_back( 1.0f, -1.0f);
        vertexes.emplace_back( 1.0f,  1.0f);
        vertexes.emplace_back(-1.0f,  1.0f);
        platform.setVertexes(vertexes);
    });

    _deleteSelectedButton = new sfml_widgets::Button(_toolbarView);
    _deleteSelectedButton->setPosition(_toolbarView->getSize().x - 70.0f, 10.0f);
    _deleteSelectedButton->setSize(sf::Vector2f(60.0f, 60.0f));
    _deleteSelectedButton->setFillColor(sf::Color::Red);
    _deleteSelectedButton->setOnClickCallback([=] () {
        Model::instance().deleteCurrentIndex();
    });
}

void map_editor::MainWindow::platformAdded(const map_editor::Index& index)
{
    if (index.type() != map_editor::Index::Type::platform)
        throw map_editor::Index::InvalidIndexException(index);

    map_editor::Model::Platform* platformModel =
            static_cast<map_editor::Model::Platform*>(index.object());
    map_editor::Platform* platform = new map_editor::Platform(platformModel,
                                                              _worldView);
    _platforms.push_back(platform);

    platform->setOnClickCallback([=] () {
        map_editor::Model::instance().selectIndex(index);
    });

    std::cout << "Platform created: " << std::to_string(index) << std::endl;
}

void map_editor::MainWindow::platformDeleted(const map_editor::Index& index)
{
    map_editor::Model::Platform* platformModel =
            static_cast<map_editor::Model::Platform*>(index.object());

    auto platformIter = std::find_if(_platforms.begin(), _platforms.end(),
    [&] (map_editor::Platform* platform) {
        return platform->platformModel() == platformModel;
    });
    if (platformIter == _platforms.end())
        return;

    if (_platformDelegate != nullptr)
    {
        if (_platformDelegate->platform() == *platformIter)
        {
            delete _platformDelegate;
            _platformDelegate = nullptr;
        }
    }

    auto platformIterEnd = platformIter;
    std::advance(platformIterEnd, 1);
    _platforms.erase(platformIter, platformIterEnd);

    _worldView->deleteWidget(*platformIter);

    std::cout << "Platform deleted: " << std::to_string(index) << std::endl;
}

void map_editor::MainWindow::platformUpdated(const map_editor::Index& index)
{
    map_editor::Model::Platform* platformModel =
            static_cast<map_editor::Model::Platform*>(index.object());

    auto platformIter = std::find_if(_platforms.begin(), _platforms.end(),
    [=] (map_editor::Platform* platform) {
        return platform->platformModel() == platformModel;
    });
    if (platformIter == _platforms.end())
        return;

    map_editor::Platform* platform = *platformIter;

    platform->setPointCount(platformModel->vertexes().size());
    int i = 0;
    for (const sf::Vector2f& vertex : platformModel->vertexes())
        platform->setPoint(i++, vertex);

    std::cout << "Platform updated: " << std::to_string(index) << std::endl;
}

void map_editor::MainWindow::indexSelected(const map_editor::Index& index)
{
    map_editor::Model::Platform* platformModel =
            static_cast<map_editor::Model::Platform*>(index.object());

    auto platformIter = std::find_if(_platforms.begin(), _platforms.end(),
    [=] (map_editor::Platform* platform) {
        return platform->platformModel() == platformModel;
    });
    if (platformIter == _platforms.end())
        return;

    map_editor::Platform* platform = *platformIter;

    if (_platformDelegate != nullptr)
        delete _platformDelegate;
    _platformDelegate = new map_editor::PlatformDelegate(platform, _worldView);

    std::cout << "Index selected: " << std::to_string(index) << std::endl;
}
