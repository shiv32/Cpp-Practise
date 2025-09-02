#include <iostream>

// Abstract base class with template method
class Beverage
{
protected:
    virtual void boilWater() { std::cout << "Boiling water\n"; }
    virtual void brew() = 0;
    virtual void pourInCup() { std::cout << "Pouring into cup\n"; }
    virtual void addCondiments() = 0;

public:
    // Template method - defines algorithm structure
    void prepareBeverage()
    {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }
    virtual ~Beverage() = default;
};

// Concrete implementation for Coffee
class Coffee : public Beverage
{
protected:
    void brew() override
    {
        std::cout << "Brewing coffee grounds\n";
    }
    void addCondiments() override
    {
        std::cout << "Adding sugar and milk\n";
    }
};

// Concrete implementation for Tea
class Tea : public Beverage
{
protected:
    void brew() override
    {
        std::cout << "Steeping tea bag\n";
    }
    void addCondiments() override
    {
        std::cout << "Adding lemon\n";
    }
};

int main()
{
    Coffee coffee;
    Tea tea;

    std::cout << "Making coffee:\n";
    coffee.prepareBeverage();

    std::cout << "\nMaking tea:\n";
    tea.prepareBeverage();

    return 0;
}