#ifndef PLATFORMMODEL_H
#define PLATFORMMODEL_H

#include <vector>

#include "SFML/System/Vector2.hpp"

#include "MapEditor/Index.h"

namespace map_editor
{
    class PlatformModel;
}

class map_editor::PlatformModel : public map_editor::Indexed
{
public:
    sf::Vector2f vertex(uint32_t vertexNumber);
    void setVertex(uint32_t vertexNumber, const sf::Vector2f& position);

    const std::vector<sf::Vector2f>& vertexes() const;
    void setVertexes(const std::vector<sf::Vector2f>& vertexes);

private:
    std::vector<sf::Vector2f> _vertexes;
};

#endif // PLATFORMMODEL_H
