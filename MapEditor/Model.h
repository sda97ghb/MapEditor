#ifndef MODEL_H
#define MODEL_H

#include "MapEditor/Platform.h"

class Model
{
public:
    class Index
    {
    public:
        enum class Type
        {
            null,
            platform
        };

        Index(Type type_, Properted* object_) :
            type(type_),
            object(object_)
        {}

        Type type;

        Properted* object;

        static Index zero()
        {
            return Index(Type::null, nullptr);
        }
    };

    static Model& instance();

    Platform& createPlatform();

    std::list<Platform>& platforms();

    void setCurrentPlatform(Platform& platform);

    Platform* currentPlatform() const;

    Index currentIndex();

private:
    Model();

    Model(const Model& model) = delete;
    void operator= (const Model& model) = delete;

    std::list<Platform> _platforms;

    Platform* _currentPlatform;
};

#endif // MODEL_H
