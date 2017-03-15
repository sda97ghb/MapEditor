#ifndef MAP_EDITOR_INDEX_H
#define MAP_EDITOR_INDEX_H

#include <stdexcept>

namespace map_editor
{
    class Index;
    class Indexed;
}

namespace std
{
    std::string to_string(const map_editor::Index& index);
}

class map_editor::Index
{
public:
    class InvalidIndexException : public std::logic_error
    {
    public:
        InvalidIndexException(const map_editor::Index& index) :
            std::logic_error("Incorrect index " + std::to_string(index))
        {}
    };

    enum class Type
    {
        undefined,
        platform
    };

    Index();
    Index(Type type, map_editor::Indexed* object);

    Type type() const;
    map_editor::Indexed* object() const;

    void set(Type type, map_editor::Indexed* object);

private:
    Type _type;
    map_editor::Indexed* _object;
};

class map_editor::Indexed
{
};

#endif // MAP_EDITOR_INDEX_H
