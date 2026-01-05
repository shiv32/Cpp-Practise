#include <iostream>
#include <memory>

class Person
{
    std::string _name{}; // handle memory
public:
    Person(std::string_view name) : _name(name.data())
    {
    }

    void greet()
    {
        std::clog << "Hello, I am " << _name << std::endl;
    }
};

int main(int argc, char *argv[])
{
    auto personA = std::make_shared<Person>("shiv");
    auto personB = personA; // copy ctor
    auto personC = std::move(personA); // move ctor

    personB->greet();
    personC->greet();

    return 0;
}