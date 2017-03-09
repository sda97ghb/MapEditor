#include "MapEditor/Model.h"
#include "MapEditor/PanelView.h"
#include "MapEditor/PlatformPropertiesDelegate.h"

PanelView::PanelView(Window* window) :
    _window(window),
    _delegate(nullptr)
{
    setSize(300.0f, 700.0f);
    setCenter(150.0f, 350.0f);
    setViewport(sf::FloatRect(0.8f, 0.1f, 0.2f, 1.0f)); // 1500 * 0.2 = 300

    Model::instance().addSubsriber(*this);
}

void PanelView::paint()
{
    sf::RectangleShape splitter;
    splitter.setFillColor(sf::Color(50, 50, 50));
    splitter.setPosition(0.0f, 0.0f);
    splitter.setSize(sf::Vector2f(2.0f, getSize().y));
    _window->draw(splitter);

    if (_delegate != nullptr)
        _delegate->paint(*_window);
}

void PanelView::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x, event.y));

    _delegate->testForClick(cursorPos);
}

void PanelView::elementChanged(Index index)
{
    updateDelegate(index);
}

void PanelView::elementSelected(Index index)
{
    updateDelegate(index);
}

void PanelView::updateDelegate(Index index)
{
    switch (index.type)
    {
        case Index::Type::platform :
        {
            if (_delegate != nullptr)
                delete static_cast<PlatformPropertiesDelegate*>(_delegate);
            _delegate = new PlatformPropertiesDelegate();
            PlatformPropertiesDelegate* platformDelegate =
                            static_cast<PlatformPropertiesDelegate*>(_delegate);

            Platform& platform = *static_cast<Platform*>(index.object);

            platformDelegate->setPlatform(platform);
        } break;
        case Index::Type::null :
            break;
    }

}
