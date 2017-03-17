#include <iostream>

#include "MapEditor/Model.h"
#include "MapEditor/ModelSaver.h"

using namespace tinyxml2;

map_editor::ModelSaver::ModelSaver() :
    _doc(nullptr)
{
}

//<platform>
//    <shape>
//        <vertex x="-20.0" y="-30.0"/>
//        <vertex x="20.0" y="-30.0"/>
//        <vertex x="20.0" y="0.0"/>
//        <vertex x="-20.0" y="0.0"/>
//    </shape>
//    <texture picture="Textures/stonebricks.png"/>
//</platform>

void map_editor::ModelSaver::save(const std::string& filename)
{
    if (_doc != nullptr)
        delete _doc;
    _doc = new XMLDocument();

    XMLElement* root = _doc->NewElement("world");
    _doc->LinkEndChild(root);

    XMLElement* ground = _doc->NewElement("ground");
    root->LinkEndChild(ground);
    saveGround(*ground);

    savePlayer(*root);

    _doc->SaveFile(filename.c_str());
}

void map_editor::ModelSaver::saveGround(XMLElement& groundElem)
{
    map_editor::Model& model = map_editor::Model::instance();

    XMLElement* platforms = _doc->NewElement("platforms");
    groundElem.LinkEndChild(platforms);

    for (map_editor::PlatformModel& platformModel : model.platforms())
    {
        XMLElement* platformElem = _doc->NewElement("platform");
        platforms->LinkEndChild(platformElem);
        savePlatform(platformModel, *platformElem);
    }
}

void map_editor::ModelSaver::savePlatform(map_editor::PlatformModel& platform,
                                          XMLElement& platformElem)
{
    XMLElement* shapeElem = _doc->NewElement("shape");
    platformElem.LinkEndChild(shapeElem);

    for (const sf::Vector2f& vertex : platform.vertexes())
    {
        XMLElement* vertexElem = _doc->NewElement("vertex");
        shapeElem->LinkEndChild(vertexElem);

        std::cout << vertex.x << " " << vertex.y << std::endl;

        vertexElem->SetAttribute("x", vertex.x);
        vertexElem->SetAttribute("y", vertex.y);
    }

    XMLElement* textureElem = _doc->NewElement("texture");
    platformElem.LinkEndChild(textureElem);
    textureElem->SetAttribute("picture", "Textures/stonebricks.png");
}

//    <actors>
//        <player>
//            <position x="5.5" y="0.875"/>
//            <texture picture="Textures/playerFrames.png"/>
//        </player>
//    </actors>

void map_editor::ModelSaver::savePlayer(XMLElement& rootElement)
{
    XMLElement* actorsElem = _doc->NewElement("actors");
    rootElement.LinkEndChild(actorsElem);

    XMLElement* playerElem = _doc->NewElement("player");
    actorsElem->LinkEndChild(playerElem);

    XMLElement* positionElem = _doc->NewElement("position");
    positionElem->SetAttribute("x", 0.0f);
    positionElem->SetAttribute("y", 2.0f);
    playerElem->LinkEndChild(positionElem);

    XMLElement* textureElem = _doc->NewElement("texture");
    textureElem->SetAttribute("picture", "Textures/playerFrames.png");
    playerElem->LinkEndChild(textureElem);
}
