#ifndef MAP_EDITOR_WORLD_VIEW_H
#define MAP_EDITOR_WORLD_VIEW_H

#include "SFMLWidgets/View.h"
#include "SFMLWidgets/ClickableConvex.h"

namespace map_editor
{
    class WorldViewConstructor;
}

class map_editor::WorldViewConstructor
{
public:
    WorldViewConstructor(sfml_widgets::View& worldView);

    void construct();

private:
    sfml_widgets::View& _worldView;
};

#endif // MAP_EDITOR_WORLD_VIEW_H
