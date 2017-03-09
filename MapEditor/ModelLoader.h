#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "TinyXml2/tinyxml2.h"

class ModelLoader
{
public:
    ModelLoader();

    void load(const std::string& filename);

private:
    void loadGround(const tinyxml2::XMLElement& groundElem);
    void loadPlatform(const tinyxml2::XMLElement& platformElem);

    tinyxml2::XMLDocument* _doc;
};

#endif // MODELLOADER_H
