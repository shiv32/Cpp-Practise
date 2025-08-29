#include <vector>
#include <memory>

/*
2. Open close principle
*/

class Shape
{
public:
    virtual double area() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
    double radius{};

public:
    Circle(double r) : radius(r)
    {
    }

    double area() override
    {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape
{
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w)
    {
    }

    double area() override
    {
        return length * width;
    }
};

double totalArea(const std::vector<std::unique_ptr<Shape>> &shape)
{
    double sum = 0;
    for (const auto &item : shape)
    {
        sum += item->area();
    }

    return sum;
}