#include <iostream>
#include <memory>

class Beverage
{
protected:
    virtual void addBoilWater() { std::clog << "Add boil water." << std::endl; };
    virtual void brew() = 0;
    virtual void pourInCup() { std::clog << "Pour into cup." << std::endl; };
    virtual void addCondiments() = 0;

public:
    virtual ~Beverage() = default;

    void prepareBeverage() // algorithm steps
    {
        addBoilWater();
        brew();
        pourInCup();
        addCondiments();
    }
};

class Coffee final : public Beverage
{
public:
    void brew() override
    {
        std::clog << "Brew coffee grounds." << std::endl;
    }

    void addCondiments() override
    {
        std::clog << "Add suger and milk." << std::endl;
    }
};

class Tea final : public Beverage
{
public:
    void brew() override
    {
        std::clog << "Steeping tea bag." << std::endl;
    }

    void addCondiments() override
    {
        std::clog << "Add lemon." << std::endl;
    }
};

int main()
{
    auto coffee = std::make_unique<Coffee>();
    auto tea = std::make_unique<Tea>();

    // prepare coffee
    std::clog << "Prepare Coffee : " << "\n";
    coffee->prepareBeverage();

    // prepare tea
    std::clog << "Prepare Tea : " << "\n";
    tea->prepareBeverage();

    return 0;
}