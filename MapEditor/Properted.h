#ifndef PROPERTED_H
#define PROPERTED_H

#include <functional>
#include <list>
#include <map>

class Properted
{
public:
    using IntGetter_t = std::function<int()>;
    using IntSetter_t = std::function<void(int)>;

    void addIntProperty(const std::string& property,
                        const IntGetter_t& getter,
                        const IntSetter_t& setter);

    int getInt(const std::string& property);
    void setInt(const std::string& property, int value);

    std::list<std::string> intProperties() const;

    using StringGetter_t = std::function<const std::string&()>;
    using StringSetter_t = std::function<void(const std::string&)>;

    void addStringProperty(const std::string& property,
                           const StringGetter_t& getter,
                           const StringSetter_t& setter);

    const std::string& getString(const std::string& property);
    void setString(const std::string& property, const std::string& value);

    std::list<std::string> stringProperties() const;

private:
    std::map<std::string, std::pair<IntGetter_t, IntSetter_t>> _int;
    std::map<std::string, std::pair<StringGetter_t, StringSetter_t>> _string;
};

#endif // PROPERTED_H
