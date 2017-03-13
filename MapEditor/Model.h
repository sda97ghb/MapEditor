#ifndef MODEL_H
#define MODEL_H

#include <list>

#include "SFML/System/Vector2.hpp"

#include "MapEditor/Index.h"

namespace map_editor
{
    class Model;
}

class map_editor::Model
{
public:
    class Platform;

    Model();

private:
    map_editor::Index _currentIndex;

    std::list<map_editor::Model::Platform>& _platforms;
};

class map_editor::Model::Platform : public map_editor::Indexed
{
public:
//    const std::list<sf::Vector2f>& vertexes() const;

private:
    std::list<sf::Vector2f> _vertexes;
};

#endif // MODEL_H
