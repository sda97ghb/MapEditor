#ifndef MODELSAVER_H
#define MODELSAVER_H

#include <string>

#include "TinyXml2/tinyxml2.h"

namespace map_editor
{
    class ModelSaver;
    class PlatformModel;
}

class map_editor::ModelSaver
{
public:
    ModelSaver();

    void save(const std::string& filename);

private:
    void saveGround(tinyxml2::XMLElement& groundElem);
    void savePlatform(map_editor::PlatformModel& platform,
                      tinyxml2::XMLElement& platformElem);
    void savePlayer(tinyxml2::XMLElement& rootElement);

    tinyxml2::XMLDocument* _doc;
};

#endif // MODELSAVER_H
