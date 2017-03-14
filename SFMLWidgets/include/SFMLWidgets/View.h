#ifndef VIEW_H
#define VIEW_H

#include <list>

#include "SFML/Graphics/View.hpp"

#include "SFMLWidgets/EventProcessor.h"

namespace sfml_widgets
{
    class View;
    class Window;
    class Widget;
}

/// @brief Create rectangle space inside a window for placing
/// widgets on itself. It can be any virtual size and have any
/// virtual coorginate origin. For more info see SMLF View class.
class sfml_widgets::View : public sf::View
{
public:
    /// @brief Contructor.
    /// @param window Window where view will be placed.
    View(sfml_widgets::Window* window);

    /// @brief Automatically delete all registred wigdets.
    ~View();

    /// @brief Returns refference to the event processor.
    sfml_widgets::EventProcessor& eventProcessor();

    /// @brief Registry new widget.
    void addWidget(sfml_widgets::Widget* widget);

    /// @brief Delete registred widget.
    void deleteWidget(sfml_widgets::Widget* widget);

    /// @brief Returns the list of all registred widgets.
    std::list<sfml_widgets::Widget*>& widgets();

private:
    sfml_widgets::Window* _window; ///< The window where view placed.
    sfml_widgets::EventProcessor _eventProcessor; ///< Event processor.

    std::list<sfml_widgets::Widget*> _widgets; ///< List of all registred widgets.
};

#endif // VIEW_H
