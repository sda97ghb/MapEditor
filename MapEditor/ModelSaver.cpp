#include "MapEditor/Model.h"
#include "MapEditor/ModelSaver.h"

using namespace tinyxml2;

ModelSaver::ModelSaver() :
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

void ModelSaver::save(const std::string& filename)
{
    if (_doc != nullptr)
        delete _doc;
    _doc = new XMLDocument();

    XMLElement* root = _doc->NewElement("world");
    _doc->LinkEndChild(root);

    XMLElement* ground = _doc->NewElement("ground");
    root->LinkEndChild(ground);

    saveGround(*ground);

    _doc->SaveFile(filename.c_str());
}

void ModelSaver::saveGround(XMLElement& groundElem)
{
    Model& model = Model::instance();

    XMLElement* platforms = _doc->NewElement("platforms");
    groundElem.LinkEndChild(platforms);

    for (Platform& platform : model.platforms())
    {
        XMLElement* platformElem = _doc->NewElement("platform");
        platforms->LinkEndChild(platformElem);
        savePlatform(platform, *platformElem);
    }
}

void ModelSaver::savePlatform(Platform& platform, XMLElement& platformElem)
{
    XMLElement* shapeElem = _doc->NewElement("shape");
    platformElem.LinkEndChild(shapeElem);

    for (uint32_t i = 0; i < platform.getPointCount(); ++ i)
    {
        XMLElement* vertexElem = _doc->NewElement("vertex");
        shapeElem->LinkEndChild(vertexElem);
        const sf::Vector2f& vertex = platform.getPoint(i);
        vertexElem->SetAttribute("x", vertex.x);
        vertexElem->SetAttribute("y", vertex.y);
    }

    XMLElement* texture = _doc->NewElement("texture");
    platformElem.LinkEndChild(texture);
    texture->SetAttribute("picture", "Textures/stonebricks.png");
}
