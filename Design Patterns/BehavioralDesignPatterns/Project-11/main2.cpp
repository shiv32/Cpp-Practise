#include <iostream>
#include <memory>

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual int execute(int a, int b) const = 0;
};

class AddStrategy : public Strategy
{
public:
    int execute(int a, int b) const override
    {
        return a + b;
    }
};

class MultiplyStrategy : public Strategy
{
public:
    int execute(int a, int b) const override
    {
        return a * b;
    }
};

class Calculator
{
private:
    std::unique_ptr<Strategy> mStrategy;

public:
    void setStrategy(std::unique_ptr<Strategy> strategy)
    {
        mStrategy = std::move(strategy);
    }

    int calculate(int a, int b) const
    {
        return mStrategy->execute(a, b);
    }
};

int main()
{
    Calculator calc;

    calc.setStrategy(std::make_unique<AddStrategy>());
    std::cout << "Add: " << calc.calculate(10, 5) << '\n';

    calc.setStrategy(std::make_unique<MultiplyStrategy>());
    std::cout << "Multiply: " << calc.calculate(10, 5) << '\n';

    return 0;
}