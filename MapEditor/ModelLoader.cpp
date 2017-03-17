#include "MapEditor/Model.h"
#include "MapEditor/ModelLoader.h"
#include "MapEditor/PlatformModel.h"

using namespace tinyxml2;

map_editor::ModelLoader::ModelLoader() :
    _doc(nullptr)
{
}

void map_editor::ModelLoader::load(const std::string& filename)
{
    if (_doc != nullptr)
        delete _doc;
    _doc = new XMLDocument();

    _doc->LoadFile(filename.c_str());

    XMLElement* root = _doc->RootElement();

    if (std::string(root->Name()) != "world")
        throw std::logic_error("it's not a map save file");

    XMLElement* groundElem = root->FirstChildElement("ground");
    if (groundElem == nullptr)
        throw std::logic_error("file has no ground section");
    loadGround(*groundElem);
}

void map_editor::ModelLoader::loadGround(const tinyxml2::XMLElement& groundElem)
{
    const XMLElement* platformsElem = groundElem.FirstChildElement("platforms");
    if (platformsElem == nullptr)
        throw std::logic_error("ground has no platforms section");

    for (const XMLElement* platformElem = platformsElem->FirstChildElement("platform");
         platformElem != nullptr;
         platformElem = platformElem->NextSiblingElement("platform"))
        loadPlatform(*platformElem);
}

void map_editor::ModelLoader::loadPlatform(const tinyxml2::XMLElement& platformElem)
{
    const XMLElement* shapeElem = platformElem.FirstChildElement("shape");
    if (shapeElem == nullptr)
        throw std::logic_error("there is platform without shape");

    std::vector<sf::Vector2f> vertexes;
    for (const XMLElement* vertexElem = shapeElem->FirstChildElement("vertex");
         vertexElem != nullptr;
         vertexElem = vertexElem->NextSiblingElement("vertex"))
    {
        float x;
        float y;
        vertexElem->QueryFloatAttribute("x", &x);
        vertexElem->QueryFloatAttribute("y", &y);
        vertexes.emplace_back(x, y);
    }
    map_editor::PlatformModel& platform =
            map_editor::Model::instance().createPlatform();
    platform.setVertexes(vertexes);

//    static sf::Texture texture;
//    texture.loadFromFile("C:/Projects/Game/Textures/stonebricks.png");
//    texture.setRepeated(true);
//    platform.setTexture(&texture);
//    platform.setTextureRect(sf::IntRect(0, 0,
//                                        16 * platform.width(),
//                                        16 * platform.height()));
}
