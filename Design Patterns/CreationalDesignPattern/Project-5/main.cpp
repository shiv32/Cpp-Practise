#include <iostream>
#include <memory>

class Shape
{
public:
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle final : public Shape
{
private:
    int radius{};

public:
    Circle(int r) : radius(r) {};

    std::unique_ptr<Shape> clone() const override
    {
        return std::make_unique<Circle>(*this);
    }

    void draw() const override
    {
        std::clog << "Draw Circle with radius " << radius << std::endl;
    }
};

int main()
{
    Circle cr(10);
    cr.draw();

    auto cloneCr = cr.clone();
    cloneCr->draw();

    //its deep copy address will be different
    std::clog << "cr address : " << &cr << std::endl;
    std::clog << "cloneCr address : " << &cloneCr << std::endl;

    return 0;
}