#include <iostream>
#include <memory>

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

class SmartPrinter : public IPrinter, public IScanner
{
public:
    void scan() override { std::clog << "SmartPrinter scanning" << "\n"; }
    void print() override { std::clog << "SmartPrinter printing" << "\n"; }
};

void Print(std::unique_ptr<IPrinter> printer)
{
    printer->print();
}

void Scan(std::unique_ptr<IScanner> scanner)
{
    scanner->scan();
}

// template <typename T>
// void Print(std::unique_ptr<T> printer)
// {
//     printer->print();
// }

// template <typename T>
// void Scan(std::unique_ptr<T> scanner)
// {
//     scanner->scan();
// }