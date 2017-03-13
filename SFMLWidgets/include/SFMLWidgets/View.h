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

class sfml_widgets::View : public sf::View
{
public:
    View(sfml_widgets::Window* window);

    ~View();

    sfml_widgets::EventProcessor& eventProcessor();

    void addWidget(sfml_widgets::Widget* widget);

    std::list<sfml_widgets::Widget*>& widgets();

private:
    sfml_widgets::Window* _window;
    sfml_widgets::EventProcessor _eventProcessor;

    std::list<sfml_widgets::Widget*> _widgets;
};

#endif // VIEW_H
