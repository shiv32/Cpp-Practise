#include <iostream>
#include <vector>
#include <memory>

/*
1. Single responsibility principle
*/
class InvoiceData
{
private:
    std::vector<std::string> data;

public:
    void addItem(std::string_view item)
    {
        data.push_back(item.data());
    }

    void print()
    {
        for (const auto &item : data)
        {
            std::clog << item << "\n";
        }
    }
};

class InvoicePrint
{
public:
    static void print(std::unique_ptr<InvoiceData> data)
    {
        data->print();
    }
};

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

int main()
{
    // 1. SRP
    auto invoiceData = std::make_unique<InvoiceData>();
    invoiceData->addItem("Book");
    invoiceData->addItem("Pen");
    InvoicePrint::print(std::move(invoiceData));

    // 2. open-close
    std::vector<std::unique_ptr<Shape>> shape;
    shape.push_back(std::make_unique<Circle>(2));
    shape.push_back(std::make_unique<Rectangle>(5, 6));
    std::clog << "total area : " << totalArea(shape) << "\n";

    return 0;
}