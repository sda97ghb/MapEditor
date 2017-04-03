#include "SFMLWidgets/TextWidget.h"
#include "SFMLWidgets/Window.h"

sfml_widgets::TextWidget::TextWidget(sfml_widgets::View* view):
    Widget(view)
{
    const std::string FONTS_DIR = "C:/Projects/Builds/build-GameMapEditor-Desktop_Qt_5_7_0_MinGW_32bit-Debug/MapEditor/debug/Fonts";
    _font.loadFromFile(FONTS_DIR + "/open-sans/OpenSans-Regular.ttf");
    setFont(_font);
    setCharacterSize(12);
    setFillColor(sf::Color::Black);
}

void sfml_widgets::TextWidget::paint(sfml_widgets::Window& window)
{
    window.draw(*this);
}
