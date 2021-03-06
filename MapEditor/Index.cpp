#include "MapEditor/Index.h"

#include <string>

std::string std::to_string(const map_editor::Index& index)
{
    std::string type = "";
    switch (index.type())
    {
        case map_editor::Index::Type::undefined : type = "undefined"; break;
        case map_editor::Index::Type::platform  : type = "platform";  break;
    }
    return "Index{type:" + type + ", object:" +
            std::to_string(reinterpret_cast<size_t>(index.object())) + "}";
}

map_editor::Index::Index() :
    _type(Type::undefined),
    _object(nullptr)
{
}

map_editor::Index::Index(map_editor::Index::Type type,
                         map_editor::Indexed* object) :
    _type(type),
    _object(object)
{
}

map_editor::Index::Type map_editor::Index::type() const
{
    return _type;
}

map_editor::Indexed* map_editor::Index::object() const
{
    return _object;
}

void map_editor::Index::set(map_editor::Index::Type type,
                            map_editor::Indexed* object)
{
    _type = type;
    _object = object;
}

//-------- Indexes --------//

#include "MapEditor/PlatformModel.h"

map_editor::Index map_editor::PlatformIndex(map_editor::PlatformModel* platform)
{
    return map_editor::Index(map_editor::Index::Type::platform, platform);
}

bool map_editor::isPlatformIndex(const map_editor::Index& index)
{
    return index.type() == map_editor::Index::Type::platform;
}

map_editor::PlatformModel* map_editor::indexToPlatformModel(
        const map_editor::Index& index)
{
    return static_cast<map_editor::PlatformModel*>(index.object());
}
