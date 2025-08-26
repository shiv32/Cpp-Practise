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

/*
  4. Interface segregation principle
*/
class IPrinter
{
public:
    virtual void print() = 0;
    virtual ~IPrinter() = default;
};

class IScanner
{
public:
    virtual void scan() = 0;
    virtual ~IScanner() = default;
};

class SimplePrinter : public IPrinter
{
public:
    void print() override { std::clog << "SimplePrinter printing" << "\n"; }
};

class SmartPrinter : public IPrinter, IScanner
{
public:
    void scan() override { std::clog << "SmartPrinter scanning" << "\n"; }
    void print() override { std::clog << "SmartPrinter printing" << "\n"; }
};

// void Print(std::unique_ptr<IPrinter> printer)
// {
//     printer->print();
// }

// void Scan(std::unique_ptr<IScanner> scanner)
// {
//     scanner->scan();
// }

template <typename T>
void Print(std::unique_ptr<T> printer)
{
    printer->print();
}

template <typename T>
void Scan(std::unique_ptr<T> scanner)
{
    scanner->scan();
}

int main()
{
    // 1. SRP
    std::clog << "1. SRP" << "\n";
    auto invoiceData = std::make_unique<InvoiceData>();
    invoiceData->addItem("Book");
    invoiceData->addItem("Pen");
    InvoicePrint::print(std::move(invoiceData));

    // 2. open-close
    std::clog << "2. open-close" << "\n";
    std::vector<std::unique_ptr<Shape>> shape;
    shape.push_back(std::make_unique<Circle>(2));
    shape.push_back(std::make_unique<Rectangle>(5, 6));
    std::clog << "total area : " << totalArea(shape) << "\n";

    // 3.LSP
    std::clog << "3. LSP" << "\n";
    BirdFly(std::move(std::make_unique<Sparrow>()));
    BirdFly(std::move(std::make_unique<Crow>()));

    // 4. ISP
    std::clog << "4. ISP" << "\n";
    Print(std::move(std::make_unique<SimplePrinter>()));
    // Scan(std::move(std::make_unique<SimplePrinter>())); //compile error
    Print(std::move(std::make_unique<SmartPrinter>()));
    Scan(std::move(std::make_unique<SmartPrinter>()));

    return 0;
}