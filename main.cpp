//#include "MapEditor/MainWindow.h"

#include <iostream>

#include "SFMLWidgets/Button.h"
#include "SFMLWidgets/ClickableConvex.h"
#include "SFMLWidgets/MovableRectangle.h"
#include "SFMLWidgets/View.h"
#include "SFMLWidgets/Window.h"

namespace map_editor { class MainWindow; class MovableRectangle; }

class map_editor::MainWindow : public sfml_widgets::Window
{
public:
    MainWindow();

    void incereaseRaiting();
    void decreaseRaiting();

    void callModerator();

private:
    sfml_widgets::View* _view1;
    sfml_widgets::View* _view2;

    sfml_widgets::Button* _button1;

    sfml_widgets::ClickableConvex* _rect1;
    sfml_widgets::ClickableConvex* _rect2;

    sfml_widgets::MovableRectangle* _movRec;

    int raiting;
};

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    map_editor::MainWindow window;
    window.run();

    return 0;
}

map_editor::MainWindow::MainWindow() :
    sfml_widgets::Window(1000, 400, "SFMLWidgets test")
{
    _view1 = new sfml_widgets::View(this);
    _view2 = new sfml_widgets::View(this);

    _view1->setViewport(sf::FloatRect(0.0f, 0.0f, 0.6f, 1.0f));
    _view1->setSize(6.0f, -4.0f);
    _view1->setCenter(0.0f, 0.0f);

    _view2->setViewport(sf::FloatRect(0.7f, 0.0f, 0.4f, 1.0f));
    _view2->setSize(400.0f, 400.0f);
    _view2->setCenter(200.0f, 200.0f);

    _button1 = new sfml_widgets::Button(_view2);
    _button1->setSize(sf::Vector2f(50.0f, 50.0f));
    _button1->setPosition(10.0f, 10.0f);
    _button1->setOnClickCallback([=] () {callModerator();});

    _rect1 = new sfml_widgets::ClickableConvex(_view1);
    _rect1->setFillColor(sf::Color::Green);
    _rect1->setPointCount(3);
    _rect1->setPoint(0, sf::Vector2f(-0.5f, 0.1f));
    _rect1->setPoint(1, sf::Vector2f( 0.5f, 0.1f));
    _rect1->setPoint(2, sf::Vector2f( 0.0f, 0.6f));
    _rect1->setOnClickCallback([=] () {incereaseRaiting();});

    _rect2 = new sfml_widgets::ClickableConvex(_view1);
    _rect2->setFillColor(sf::Color::Red);
    _rect2->setPointCount(3);
    _rect2->setPoint(0, sf::Vector2f(-0.5f, -0.1f));
    _rect2->setPoint(1, sf::Vector2f( 0.5f, -0.1f));
    _rect2->setPoint(2, sf::Vector2f( 0.0f, -0.6f));
    _rect2->setOnClickCallback([=] () {decreaseRaiting();});

    raiting = 0;

    _movRec = new sfml_widgets::MovableRectangle(_view1);
    _movRec->setSize(sf::Vector2f(0.3f, 0.3f));
    _movRec->setPosition(1.35f, -0.15f);
    _movRec->setFillColor(sf::Color::Yellow);
    _movRec->setOnReleaseCallback([=] () {
        std::cout << "Released at (" << _movRec->getPosition().x << ";" <<
                                        _movRec->getPosition().y << ")" << std::endl;
    });
}

void map_editor::MainWindow::incereaseRaiting()
{
    std::cout << "Raiting: " << ++raiting << "!" << std::endl;
}

void map_editor::MainWindow::decreaseRaiting()
{
    std::cout << "Raiting: " << --raiting << "!" << std::endl;
}

void map_editor::MainWindow::callModerator()
{
    static int N = 0;
    std::cout << "You called moderator " << ++N << " times!" <<
                 std::endl;
}
