#ifndef BUTTON_H
#define BUTTON_H

#include "SFMLWidgets/ClickableRectangle.h"

namespace sfml_widgets
{
    class Button;
}

class sfml_widgets::Button : public sfml_widgets::ClickableRectangle
{
public:
    Button(sfml_widgets::View* view);
};

#endif // BUTTON_H
