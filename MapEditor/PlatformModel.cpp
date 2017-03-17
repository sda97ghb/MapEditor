#include "MapEditor/Model.h"
#include "MapEditor/PlatformModel.h"

const std::vector<sf::Vector2f>& map_editor::PlatformModel::vertexes() const
{
    return _vertexes;
}

void map_editor::PlatformModel::setVertexes(
        const std::vector<sf::Vector2f>& vertexes)
{
    _vertexes = vertexes;
    Model::instance().notifyPlatformUpdated(
                map_editor::Index(map_editor::Index::Type::platform,
                                  this));
}

sf::Vector2f map_editor::PlatformModel::vertex(uint32_t vertexNumber)
{
    return _vertexes[vertexNumber];
}

void map_editor::PlatformModel::setVertex(uint32_t vertexNumber,
                                          const sf::Vector2f& position)
{
    _vertexes[vertexNumber] = position;
}
