#include <iostream>

#include "SFML/Graphics/Text.hpp"

#include "MapEditor/MainWindow.h"
#include "MapEditor/Model.h"
#include "MapEditor/ModelLoader.h"
#include "MapEditor/ModelSaver.h"

MainWindow::MainWindow() :
    Window(1500, 700, "Game map editor"), // 1500 * 0.8 == 1200
    _currentPlatform(nullptr),
    _panelView(this),
    _toolbarView(this),
    _worldView(this)
{
    ModelLoader().load("C:/Projects/Builds/"
                       "build-GameMapEditor-Desktop_Qt_5_7_0_MinGW_32bit-Debug/"
                       "debug/MapLevels/map1.xml");
//    Model& model = Model::instance();
//    {
//        Platform& platform = model.createPlatform();
//        platform.move(0.0f, 0.0f);
////        platform.shape.setFillColor(sf::Color(100, 80, 100));

//        std::list<sf::Vector2f> vertexes;
//        vertexes.push_back(sf::Vector2f(-20.0f, -5.0f));
//        vertexes.push_back(sf::Vector2f( 20.0f, -5.0f));
//        vertexes.push_back(sf::Vector2f( 20.0f,  0.0f));
//        vertexes.push_back(sf::Vector2f(-20.0f,  0.0f));
//        platform.setShape(vertexes);

//        platform.setFillColor(sf::Color(255, 255, 255));
//        static sf::Texture texture;
//        texture.loadFromFile("C:/Projects/Game/Textures/stonebricks.png");
//        texture.setRepeated(true);
//        platform.setTexture(&texture);
//        platform.setTextureRect(sf::IntRect(0, 0, 16 * 40, 16 * 5));
//    }
//    {
//        Platform& platform = model.createPlatform();
//        platform.move(0.0f, 0.0f);
////        platform.shape.setFillColor(sf::Color(100, 80, 100));

//        std::list<sf::Vector2f> vertexes;
//        vertexes.push_back(sf::Vector2f(-20.0f,  5.0f));
//        vertexes.push_back(sf::Vector2f( 20.0f,  5.0f));
//        vertexes.push_back(sf::Vector2f( 20.0f, 10.0f));
//        vertexes.push_back(sf::Vector2f(-20.0f, 10.0f));
//        platform.setShape(vertexes);

//        platform.setFillColor(sf::Color(255, 255, 255));
//        static sf::Texture texture;
//        texture.loadFromFile("C:/Projects/Game/Textures/stonebricks.png");
//        texture.setRepeated(true);
//        platform.setTexture(&texture);
//        platform.setTextureRect(sf::IntRect(0, 0, 16 * 40, 16 * 5));
//    }
}

MainWindow::~MainWindow()
{
    ModelSaver().save("C:/Projects/Builds/"
                      "build-GameMapEditor-Desktop_Qt_5_7_0_MinGW_32bit-Debug/"
                      "debug/MapLevels/map1.xml");
}

void MainWindow::paint()
{
    const sf::Color CLEAR_COLOR = sf::Color(30, 30, 30);
    clear(CLEAR_COLOR);

    setView(_panelView);
    _panelView.paint();

    setView(_toolbarView);
    _toolbarView.paint();

    setView(_worldView);
    _worldView.paint();

    display();
}

void MainWindow::update()
{
    const float SCROLLING_SPEED = 0.03f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        _worldView.move(-SCROLLING_SPEED, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _worldView.move(SCROLLING_SPEED, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _worldView.move(0.0f, -SCROLLING_SPEED);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        _worldView.move(0.0f, SCROLLING_SPEED);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        _worldView.setCenter(0.0f, 0.0f);
}

void MainWindow::mousePressedEvent(const sf::Event::MouseButtonEvent& event)
{
    if (event.x < 1200)
    {
        setView(_worldView);
        _worldView.mousePressedEvent(event);
    }
}

void MainWindow::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    if (event.y < 80)
    {
        setView(_toolbarView);
        _toolbarView.mouseReleasedEvent(event);
    }
    else
    {
        if (event.x < 1200)
        {
            setView(_worldView);
            _worldView.mouseReleasedEvent(event);
        }
        else
        {
            setView(_panelView);
            _panelView.mouseReleasedEvent(event);
        }
    }
}

void MainWindow::mouseMovedEvent(const sf::Event::MouseMoveEvent& event)
{
    if (event.x < 1200)
    {
        setView(_worldView);
        _worldView.mouseMovedEvent(event);
    }
}
