#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics/Text.hpp"
#include "SFMLWidgets/ClickableRectangle.h"

namespace sfml_widgets
{
    class Button;
}

/// @brief Clickable rectangle button.
/// @details Creates button with given onClick callback.
/// Callback can be lambda or usual c++ function. If you want to call your
/// class methods you can use [=](){yourMethod();} construction.
/// Callback will be called after mouse release event when cursor
/// is on the button.
///
/// Usage:
/// Assume you have a view for your window.
/// private: sfml_widgets::View* _view;
///
/// In private section of your window class
/// sfml_widgets::Button* _button;
///
/// In window constructor
/// _button = new sfml_widgets::Button(_view);
///
/// @note You must not delete button manualy.
class sfml_widgets::Button : public sfml_widgets::ClickableRectangle
{
public:
    /// @brief Constructor.
    /// @details Place button on given view and registry it in view's window.
    /// @param view View where button will be placed.
    Button(sfml_widgets::View* view);

    /// @brief Set fill color for the button.
    void setFillColor(const sf::Color& color);

    /// @brief Set button text.
    void setText(const std::string& text);

    /// @brief Return button text.
    std::string text() const;

private:
    /// @brief Paint button.
    void paint(sfml_widgets::Window &window);

    sf::Text _text; ///< Button text.
    sf::Font _font; ///< Button text font.
};

#endif // BUTTON_H
