#include "MapEditor/Properted.h"

void Properted::addIntProperty(const std::string& property,
                               const IntGetter_t& getter,
                               const IntSetter_t& setter)
{
    _int[property] = std::make_pair(getter, setter);
}

int Properted::getInt(const std::string& property)
{
    return _int[property].first();
}

void Properted::setInt(const std::string& property, int value)
{
    _int[property].second(value);
}

std::list<std::string> Properted::intProperties() const
{
    std::list<std::string> list;
    if (_int.empty())
        return list;
    for (const std::pair<std::string, std::pair<IntGetter_t, IntSetter_t>>& property : _int)
        list.push_back(property.first);
    return list;
}

void Properted::addStringProperty(const std::string& property,
                                  const Properted::StringGetter_t& getter,
                                  const Properted::StringSetter_t& setter)
{
    _string[property] = std::make_pair(getter, setter);
}

const std::string& Properted::getString(const std::string& property)
{
    return _string[property].first();
}

void Properted::setString(const std::string& property,
                          const std::string& value)
{
    _string[property].second(value);
}

std::list<std::string> Properted::stringProperties() const
{
    std::list<std::string> list;
    if (_int.empty())
        return list;
    for (const std::pair<std::string, std::pair<StringGetter_t, StringSetter_t>>& property : _string)
        list.push_back(property.first);
    return list;
}
