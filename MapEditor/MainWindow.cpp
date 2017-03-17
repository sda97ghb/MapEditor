#include <iostream>

#include "SFML/Window/Keyboard.hpp"

#include "MapEditor/MainWindow.h"
#include "MapEditor/Model.h"
#include "MapEditor/ModelLoader.h"
#include "MapEditor/ModelSaver.h"

map_editor::MainWindow::MainWindow() :
    sfml_widgets::Window(1500, 800, "SFMLWidgets test", sf::Style::Default),
    _platformDelegate(nullptr),
    _platformPropertiesDelegate(nullptr)
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

    _panelSplitter = new sfml_widgets::RectangleWidget(_toolbarView);
    _panelSplitter->setFillColor(sf::Color(120, 120, 120));
    _panelSplitter->setPosition(0.0f, _toolbarView->getSize().y - 2.0f);
    _panelSplitter->setSize(sf::Vector2f(_toolbarView->getSize().x, 2.0f));

    _panelSplitter = new sfml_widgets::RectangleWidget(_panelView);
    _panelSplitter->setFillColor(sf::Color(120, 120, 120));
    _panelSplitter->setPosition(0.0f, 0.0f);
    _panelSplitter->setSize(sf::Vector2f(2.0f, _panelView->getSize().y));

    _worldOriginWidget = new sfml_widgets::RectangleWidget(_worldView);
    _worldOriginWidget->setFillColor(sf::Color::Red);
    _worldOriginWidget->setPosition(0.0f, 0.0f);
    _worldOriginWidget->setSize(sf::Vector2f(0.1f, 0.1f));

    constructToolbar();
}

void map_editor::MainWindow::constructToolbar()
{
//    const std::string SAVE_FILE = "C:/Projects/save.xml";
    const std::string SAVE_FILE = "C:/Projects/Builds/build-Game-Desktop_Qt_5_7_0_MinGW_32bit-Debug/debug/MapLevels/LEVEL_ONE.xml";

    _loadMapButton = new sfml_widgets::Button(_toolbarView);
    _loadMapButton->setPosition(10.0f, 10.0f);
    _loadMapButton->setSize(sf::Vector2f(60.0f, 60.0f));
    _loadMapButton->setFillColor(sf::Color(255, 255, 0));
    _loadMapButton->setText("Load");
    _loadMapButton->setOnClickCallback([=] () {
        map_editor::Model::instance().drop();
        map_editor::ModelLoader().load(SAVE_FILE);
    });

    _saveMapButton = new sfml_widgets::Button(_toolbarView);
    _saveMapButton->setPosition(80.0f, 10.0f);
    _saveMapButton->setSize(sf::Vector2f(60.0f, 60.0f));
    _saveMapButton->setFillColor(sf::Color(163, 73, 164));
    _saveMapButton->setText("Save");
    _saveMapButton->setOnClickCallback([=] () {
        map_editor::ModelSaver().save(SAVE_FILE);
    });

    _addPlatformButton = new sfml_widgets::Button(_toolbarView);
    _addPlatformButton->setPosition(150.0f, 10.0f);
    _addPlatformButton->setSize(sf::Vector2f(60.0f, 60.0f));
    _addPlatformButton->setFillColor(sf::Color(100, 100, 100));
    _addPlatformButton->setText("  Add\n"
                                "platform");
    _addPlatformButton->setOnClickCallback([=] () {
        map_editor::PlatformModel& platform =
                map_editor::Model::instance().createPlatform();

        std::vector<sf::Vector2f> vertexes;
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
    _deleteSelectedButton->setText("Delete");
    _deleteSelectedButton->setOnClickCallback([=] () {
        Model::instance().deleteCurrentIndex();
    });
}

map_editor::PlatformWidget* map_editor::MainWindow::findPlatformWidgetForModel(
        map_editor::PlatformModel* platformModel)
{
    auto platformIter = std::find_if(_platformWidgets.begin(),
                                     _platformWidgets.end(),
    [platformModel] (map_editor::PlatformWidget* platform) {
        return platform->platformModel() == platformModel;
    });
    if (platformIter == _platformWidgets.end())
        return nullptr;
    return *platformIter;
}

void map_editor::MainWindow::deletePlatformWidget(
        map_editor::PlatformWidget* platformWidget)
{
    _worldView->deleteWidget(platformWidget);
    _platformWidgets.erase(std::find(_platformWidgets.begin(),
                                     _platformWidgets.end(),
                                     platformWidget));
}

void map_editor::MainWindow::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        _worldView->move(-0.1f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _worldView->move(0.1f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _worldView->move(0.0f, -0.1f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        _worldView->move(0.0f, 0.1f);
}

void map_editor::MainWindow::platformAdded(const map_editor::Index& index)
{
    if (!map_editor::isPlatformIndex(index) || index.object() == nullptr)
        throw map_editor::Index::InvalidIndexException(index);

    map_editor::PlatformModel* platformModel =
            map_editor::indexToPlatformModel(index);
    map_editor::PlatformWidget* platformWidget =
            new map_editor::PlatformWidget(platformModel, _worldView);
    _platformWidgets.push_back(platformWidget);

    platformWidget->setFillColor(sf::Color(100, 100, 100));

    platformWidget->setOnClickCallback([index] () {
        map_editor::Model::instance().selectIndex(index);
    });

    std::cout << "Platform created: " << std::to_string(index) << std::endl;
}

void map_editor::MainWindow::platformDeleted(const map_editor::Index& index)
{
    if (!map_editor::isPlatformIndex(index) || index.object() == nullptr)
        throw map_editor::Index::InvalidIndexException(index);

    map_editor::PlatformModel* platformModel =
            map_editor::indexToPlatformModel(index);
    map_editor::PlatformWidget* platformWidget =
            findPlatformWidgetForModel(platformModel);
    if (platformWidget == nullptr)
        return;

    deletePlatformWidget(platformWidget);

    if (_platformDelegate != nullptr)
    {
        if (_platformDelegate->platformModel() == platformModel)
        {
            delete _platformDelegate;
            _platformDelegate = nullptr;
        }
    }

//    if (_platformPropertiesDelegate != nullptr)
//    {
//        if (_platformPropertiesDelegate->platform() ==
//            (*platformIter)->platformModel())
//        {
//            delete _platformPropertiesDelegate;
//            _platformPropertiesDelegate = nullptr;
//        }
//    }

    std::cout << "Platform deleted: " << std::to_string(index) << std::endl;
}

void map_editor::MainWindow::platformUpdated(const map_editor::Index& index)
{
    map_editor::PlatformModel* platformModel =
            map_editor::indexToPlatformModel(index);
    map_editor::PlatformWidget* platformWidget =
            findPlatformWidgetForModel(platformModel);
    if (platformWidget == nullptr)
        return;

    platformWidget->setPointCount(platformModel->vertexes().size());
    int i = 0;
    for (const sf::Vector2f& vertex : platformModel->vertexes())
        platformWidget->setPoint(i++, vertex);

    if (_platformDelegate != nullptr)
    {
        if (_platformDelegate->platformModel() == platformModel)
        {
            delete _platformDelegate;
            _platformDelegate = new map_editor::PlatformDelegate(platformModel,
                                                                 platformWidget,
                                                                 _worldView);
        }
    }

    std::cout << "Platform updated: " << std::to_string(index) << std::endl;
}

void map_editor::MainWindow::indexSelected(const map_editor::Index& index)
{
    map_editor::PlatformModel* platformModel =
            map_editor::indexToPlatformModel(index);
    map_editor::PlatformWidget* platformWidget =
            findPlatformWidgetForModel(platformModel);
    if (platformWidget == nullptr)
        return;

    if (_platformDelegate != nullptr)
        delete _platformDelegate;
    _platformDelegate = new map_editor::PlatformDelegate(platformModel,
                                                         platformWidget,
                                                         _worldView);

    if (_platformPropertiesDelegate != nullptr)
        delete _platformPropertiesDelegate;
    _platformPropertiesDelegate = new map_editor::PlatformPropertiesDelegate(
                platformModel, _panelView);

    std::cout << "Index selected: " << std::to_string(index) << std::endl;
}
