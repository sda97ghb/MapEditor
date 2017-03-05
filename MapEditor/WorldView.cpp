#include "MapEditor/MainWindow.h"
#include "MapEditor/Model.h"
#include "MapEditor/WorldView.h"

WorldView::WorldView(MainWindow* window)
{
    _window = window;

    setCenter(0.0f, 0.0f);
    // scale view to make 1 physical meter equal to 1 grapical unit
    setSize(36.0f, -21.0f); // (36x21) == (1200x700) / 100 * 3
    setViewport(sf::FloatRect(0.0f, 0.0f, 0.8f, 1.0f)); // 1500 * 0.8 = 1200

    Model::instance().addSubsriber(*this);
}

void WorldView::paint()
{
    Model& model = Model::instance();

    for (Platform& platform : model.platforms())
        _window->draw(platform);

    for (VertexButton& button : _platformDeligate.vertexButtons())
        _window->draw(button);

    sf::CircleShape zero;
    zero.setFillColor(sf::Color::Red);
    zero.setRadius(0.1f);
    zero.setPosition(0.0f, 0.0f);
    _window->draw(zero);
}

void WorldView::mousePressedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x,
                                                                    event.y));

    _platformDeligate.grabButton(cursorPos);
}

void WorldView::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x,
                                                                    event.y));
    for (Platform& platform : Model::instance().platforms())
        platform.testForClick(cursorPos);

//    Index index = Model::instance().currentIndex();

//    if (index.type == Index::Type::platform)
//        _platformDeligate.setPlatform(*static_cast<Platform*>(index.object));

    _platformDeligate.releaseButtons();
}

void WorldView::mouseMovedEvent(const sf::Event::MouseMoveEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x,
                                                                    event.y));

    _platformDeligate.moveButton(cursorPos);
}

void WorldView::elementChanged(Index index)
{
    updateDelegate(index);
}

void WorldView::elementSelected(Index index)
{
    updateDelegate(index);
}

void WorldView::updateDelegate(Index index)
{
    switch (index.type)
    {
        case Index::Type::platform :
        {
            _platformDeligate.setPlatform(*static_cast<Platform*>(index.object));
            // reset other delegates
        } break;
        case Index::Type::null :
            break;
    }
}
