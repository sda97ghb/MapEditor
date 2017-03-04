#ifndef MOVABLEBUTTON_H
#define MOVABLEBUTTON_H

#include "MapEditor/Button.h"

class MovableButton : public Button
{
public:
    MovableButton();

    void grab(const sf::Vector2f& cursorPos);
    void release();

    void move(const sf::Vector2f& cursorPos);

    void setOnMoveCallback(const std::function<void()>& function);

private:
    bool _canMove;
    float _dx;
    float _dy;

    std::function<void()> _onMoveCallback;

};

#endif // MOVABLEBUTTON_H
