#include "MapEditor/Properted.h"

void map_editor::Properted::addIntProperty(const std::string& property,
                               const map_editor::Properted::IntGetter_t& getter,
                               const map_editor::Properted::IntSetter_t& setter)
{
    _int[property] = std::make_pair(getter, setter);
}

int map_editor::Properted::getInt(const std::string& property)
{
    return _int[property].first();
}

void map_editor::Properted::setInt(const std::string& property, int value)
{
    _int[property].second(value);
}

std::list<std::string> map_editor::Properted::intProperties() const
{
    std::list<std::string> list;
    if (_int.empty())
        return list;
    for (const std::pair<std::string, std::pair<map_editor::Properted::IntGetter_t, map_editor::Properted::IntSetter_t>>& property : _int)
        list.push_back(property.first);
    return list;
}

void map_editor::Properted::addStringProperty(const std::string& property,
                                  const map_editor::Properted::StringGetter_t& getter,
                                  const map_editor::Properted::StringSetter_t& setter)
{
    _string[property] = std::make_pair(getter, setter);
}

const std::string& map_editor::Properted::getString(const std::string& property)
{
    return _string[property].first();
}

void map_editor::Properted::setString(const std::string& property,
                          const std::string& value)
{
    _string[property].second(value);
}

std::list<std::string> map_editor::Properted::stringProperties() const
{
    std::list<std::string> list;
    if (_int.empty())
        return list;
    for (const std::pair<std::string, std::pair<map_editor::Properted::StringGetter_t, map_editor::Properted::StringSetter_t>>& property : _string)
        list.push_back(property.first);
    return list;
}
