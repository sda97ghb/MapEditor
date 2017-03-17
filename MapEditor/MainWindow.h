#ifndef MAP_EDITOR_MAINWINDOW_H
#define MAP_EDITOR_MAINWINDOW_H

#include "SFMLWidgets/Button.h"
#include "SFMLWidgets/ClickableConvex.h"
#include "SFMLWidgets/MovableRectangle.h"
#include "SFMLWidgets/RectangleWidget.h"
#include "SFMLWidgets/View.h"
#include "SFMLWidgets/Window.h"

#include "MapEditor/Index.h"
#include "MapEditor/ModelSubscriber.h"
#include "MapEditor/PlatformWidget.h"
#include "MapEditor/PlatformDelegate.h"
#include "MapEditor/PlatformPropertiesDelegate.h"
#include "MapEditor/WorldViewConstructor.h"

namespace map_editor
{
    class MainWindow;
}

class map_editor::MainWindow : public sfml_widgets::Window,
                               public map_editor::ModelSubscriber
{
public:
    MainWindow();

    void platformAdded(const map_editor::Index& index);
    void platformDeleted(const map_editor::Index& index);
    void platformUpdated(const map_editor::Index& index);

    void indexSelected(const map_editor::Index& index);

private:
    void constructToolbar();

    map_editor::PlatformWidget* findPlatformWidgetForModel(
            map_editor::PlatformModel* platformModel);
    void deletePlatformWidget(map_editor::PlatformWidget* platformWidget);

    void update();

    sfml_widgets::View* _panelView;
    sfml_widgets::View* _toolbarView;
    sfml_widgets::View* _worldView;

    sfml_widgets::RectangleWidget* _panelSplitter;
    sfml_widgets::RectangleWidget* _toolbarSplitter;

    // Toolbar
    sfml_widgets::Button* _loadMapButton;
    sfml_widgets::Button* _saveMapButton;
    sfml_widgets::Button* _addPlatformButton;
    sfml_widgets::Button* _deleteSelectedButton;

    // World view
    std::list<map_editor::PlatformWidget*> _platformWidgets;
    map_editor::PlatformDelegate* _platformDelegate;
    sfml_widgets::RectangleWidget* _worldOriginWidget;

    // Panel
    map_editor::PlatformPropertiesDelegate* _platformPropertiesDelegate;
};

#endif // MAP_EDITOR_MAINWINDOW_H
