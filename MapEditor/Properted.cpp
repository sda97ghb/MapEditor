#include "MapEditor/Properted.h"

void Properted::setInt(const std::string& property, int value)
{
    _intProperties[property] = value;
}

int Properted::getInt(const std::string& property)
{
    return _intProperties[property];
}

std::list<std::string> Properted::intProperties() const
{
    std::list<std::string> list;
    if (_intProperties.empty())
        return list;
    for (const std::pair<std::string, int>& property : _intProperties)
        list.push_back(property.first);
    return list;
}
