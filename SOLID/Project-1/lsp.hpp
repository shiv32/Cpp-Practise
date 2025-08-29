#include <iostream>
#include <memory>

/*
3. LSP- liskov substituion principle
*/
class Bird
{
public:
    virtual void fly() { std::clog << "flying" << "\n"; };
    virtual ~Bird() = default;
};

class Sparrow : public Bird
{
public:
    void fly() override
    {
        std::clog << "Sparrow flying" << "\n";
    }
};

class Crow : public Bird
{
public:
    void fly() override
    {
        std::clog << "Crow flying" << "\n";
    }
};

void BirdFly(std::unique_ptr<Bird> bird)
{
    bird->fly();
}