#ifndef INDEX_H
#define INDEX_H

namespace map_editor
{
    class Index;
    class Indexed;
}

class map_editor::Index
{
public:
    enum class Type
    {
        platform
    };

    Index();

private:
    Type _type;
    map_editor::Indexed* _object;
};

class map_editor::Indexed {};

#endif // INDEX_H
