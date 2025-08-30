#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <type_traits>
#include <utility>

// Shape interface
class IShape
{
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void accept(class ShapeVisitor &visitor) = 0;
    virtual ~IShape() = default;
};

// Visitor interface
class ShapeVisitor
{
public:
    virtual void visit(IShape &shape) = 0;
    virtual ~ShapeVisitor() = default;
};

// Concrete elements
class Circle : public IShape
{
public:
    double radius = 5.0;

    void accept(ShapeVisitor &visitor) override
    {
        visitor.visit(*this);
    }

    double getArea() const override
    {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const override
    {
        return 2 * 3.14159 * radius;
    }
};

class Square : public IShape
{
public:
    double side = 4.0;

    void accept(ShapeVisitor &visitor) override
    {
        visitor.visit(*this);
    }

    double getArea() const override
    {
        return side * side;
    }

    double getPerimeter() const override
    {
        return 4 * side;
    }
};

class Triangle : public IShape
{
public:
    double base = 3.0;
    double height = 4.0;

    void accept(ShapeVisitor &visitor) override
    {
        visitor.visit(*this);
    }

    double getArea() const override
    {
        return 0.5 * base * height;
    }

    double getPerimeter() const override
    {
        // Assuming right triangle for simplicity
        return base + height +
               std::sqrt(base * base + height * height);
    }
};

// Concrete visitor for calculating measurements
class ShapeMeasurementVisitor : public ShapeVisitor
{
public:
    void visit(IShape &shape) override
    {
        area = shape.getArea();
        perimeter = shape.getPerimeter();
    }

    double getArea() const { return area; }
    double getPerimeter() const { return perimeter; }

private:
    double area = 0.0;
    double perimeter = 0.0;
};

// Common function using runtime polymorphism
void processShape(IShape &shape, ShapeVisitor &visitor)
{
    shape.accept(visitor);
}

// Utility function to get the measurement using runtime polymorphism
std::pair<double, double> getMeasurements(IShape &shape)
{
    ShapeMeasurementVisitor visitor;
    processShape(shape, visitor);
    return {visitor.getArea(), visitor.getPerimeter()};
}

int main()
{
    // Example 1: Using processShape with concrete types
    Circle circle;
    Square square;
    Triangle triangle;

    ShapeMeasurementVisitor visitor;

    std::cout << "Using processShape function:\n";
    std::cout << "Circle:\n";
    processShape(circle, visitor);
    std::cout << "Area: " << visitor.getArea() << "\n";
    std::cout << "Perimeter: " << visitor.getPerimeter() << "\n\n";

    // Example 2: Using getMeasurements utility function
    std::cout << "Using getMeasurements function:\n";
    auto [squareArea, squarePerimeter] = getMeasurements(square);
    std::cout << "Square measurements:\n";
    std::cout << "Area: " << squareArea << "\n";
    std::cout << "Perimeter: " << squarePerimeter << "\n\n";

    // Example 3: Using with polymorphic container
    std::vector<std::unique_ptr<IShape>> shapes;
    shapes.push_back(std::make_unique<Circle>());
    shapes.push_back(std::make_unique<Square>());
    shapes.push_back(std::make_unique<Triangle>());

    std::cout << "Processing polymorphic shapes:\n";
    for (const auto &shape : shapes)
    {
        processShape(*shape, visitor);
        std::cout << "Shape measurements:\n";
        std::cout << "Area: " << visitor.getArea() << "\n";
        std::cout << "Perimeter: " << visitor.getPerimeter() << "\n\n";
    }

    return 0;
}
