#include <iostream>

#include "MapEditor/Model.h"
#include "MapEditor/PanelView.h"

PanelView::PanelView(Window* window) :
    _window(window)
{
    setSize(300.0f, 700.0f);
    setCenter(150.0f, 350.0f);
    setViewport(sf::FloatRect(0.8f, 0.0f, 0.2f, 1.0f)); // 1500 * 0.2 = 300

    {
        _buttons.emplace_back();
        Button& button = _buttons.back();
        button.setPosition(20.0f, 80.0f);
        button.setSize(sf::Vector2f(150.0f, 30.0f));
        button.setCallback([this](){
            Platform& platform = Model::instance().platforms().back();
            std::list<sf::Vector2f> vertexes = {sf::Vector2f(-1.0, -1.0),
                                                sf::Vector2f( 1.0, -1.0),
                                                sf::Vector2f( 1.0,  1.0),
                                                sf::Vector2f(-1.0,  1.0)};
            platform.setShape(vertexes);
            static int n = 0;
            std::cout << "Clicked! " << n++ << std::endl;
        });
    }
}

void PanelView::paint()
{
    sf::Text text;
    sf::Font font;
    font.loadFromFile("C:/Projects/GameMapEditor/Fonts/open-sans/OpenSans-Light.ttf");
    text.setFont(font);
    text.setCharacterSize(16u);
    text.setFillColor(sf::Color::White);

    text.setPosition(3.0f, 5.0f);
    text.setString("Current platform:");
    _window->draw(text);

    text.setPosition(3.0f, 25.0f);
    text.setString(std::to_string((int)0));
    _window->draw(text);

    for (Button& button : _buttons)
        _window->draw(button);

    sf::CircleShape zero;
    zero.setFillColor(sf::Color::Red);
    zero.setRadius(2.0f);
    zero.setPosition(0.0f, 0.0f);
    _window->draw(zero);
}

void PanelView::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x, event.y));
    for (Button& button : _buttons)
        button.testForClick(cursorPos);
}
