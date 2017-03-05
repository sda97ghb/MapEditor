#ifndef PROPERTED_H
#define PROPERTED_H

#include <list>
#include <map>

class Properted
{
public:
    void setInt(const std::string& property, int value);
    int getInt(const std::string& property);

    std::list<std::string> intProperties() const;

private:
    std::map<std::string, int> _intProperties;
};

#endif // PROPERTED_H
