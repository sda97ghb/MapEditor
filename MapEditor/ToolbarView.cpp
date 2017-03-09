#include "MapEditor/Model.h"
#include "MapEditor/ToolbarView.h"

ToolbarView::ToolbarView(Window* window) :
    _window(window)
{
    setSize(1500.0f, 80.0f);
    setCenter(750.0f, 40.0f);
    setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 0.1f));

    _addPlatformButton.setSize(60.0f, 60.0f);
    _addPlatformButton.setPosition(10.0f, 10.0f);
    _addPlatformButton.setFillColor(sf::Color(121, 121, 121));
    _addPlatformButton.setCallback([] () {
        Model& model = Model::instance();

        Platform& platform = model.createPlatform();
        platform.move(0.0f, 0.0f);

        std::list<sf::Vector2f> vertexes;
        vertexes.emplace_back(-1.0f, -1.0f);
        vertexes.emplace_back( 1.0f, -1.0f);
        vertexes.emplace_back( 1.0f,  1.0f);
        vertexes.emplace_back(-1.0f,  1.0f);
        platform.setShape(vertexes);

        platform.setFillColor(sf::Color::White);
        static sf::Texture texture;
        texture.loadFromFile("C:/Projects/Game/Textures/stonebricks.png");
        texture.setRepeated(true);
        platform.setTexture(&texture);
        platform.setTextureRect(sf::IntRect(0, 0, 16 * 2, 16 * 2));
    });
}

void ToolbarView::paint()
{
    sf::RectangleShape splitter;
    splitter.setPosition(0.0f, getSize().y - 2.0f);
    splitter.setSize(sf::Vector2f(getSize().x, 2.0f));
    splitter.setFillColor(sf::Color(100, 100, 100));
    _window->draw(splitter);

    _window->draw(_addPlatformButton);
}

void ToolbarView::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x, event.y));

    _addPlatformButton.testForClick(cursorPos);
}
