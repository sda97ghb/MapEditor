#ifndef MODEL_H
#define MODEL_H

#include <list>

#include "MapEditor/Index.h"
#include "MapEditor/ModelSubscriber.h"
#include "MapEditor/Platform.h"

class Model
{
public:
    static Model& instance();

    Platform& createPlatform();

    std::list<Platform>& platforms();

    Platform* currentPlatform() const;

    Index currentIndex();

    void selectElement(Platform& platform);

    void addSubsriber(ModelSubscriber& subscriber);
    void notifySelected(Index index);
    void notifyChanged(Index index);

private:
    Model();

    Model(const Model& model) = delete;
    void operator= (const Model& model) = delete;

    std::list<Platform> _platforms;

    Index _currentIndex;
    Platform* _currentPlatform;

    std::list<ModelSubscriber*> _subsribers;
};

#endif // MODEL_H
