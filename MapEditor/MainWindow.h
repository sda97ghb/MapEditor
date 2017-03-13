#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SFMLWidgets/Button.h"
#include "SFMLWidgets/ClickableConvex.h"
#include "SFMLWidgets/MovableRectangle.h"
#include "SFMLWidgets/RectangleWidget.h"
#include "SFMLWidgets/View.h"
#include "SFMLWidgets/Window.h"

namespace map_editor
{
    class MainWindow;
}

class map_editor::MainWindow : public sfml_widgets::Window
{
public:
    MainWindow();

private:
    void constructToolbar();

    sfml_widgets::View* _panelView;
    sfml_widgets::View* _toolbarView;
    sfml_widgets::View* _worldView;

    sfml_widgets::RectangleWidget* _panelSplitter;
    sfml_widgets::RectangleWidget* _toolbarSplitter;

    // Toolbar
    sfml_widgets::Button* _addPlatformButton;
    sfml_widgets::Button* _deleteSelectedButton;
};

#endif // MAINWINDOW_H
