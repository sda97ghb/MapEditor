#ifndef MODELSAVER_H
#define MODELSAVER_H

#include <string>

#include "TinyXml2/tinyxml2.h"

class Platform;

class ModelSaver
{
public:
    ModelSaver();

    void save(const std::string& filename);

private:
    void saveGround(tinyxml2::XMLElement& groundElem);
    void savePlatform(Platform& platform, tinyxml2::XMLElement& platformElem);

    tinyxml2::XMLDocument* _doc;
};

#endif // MODELSAVER_H
