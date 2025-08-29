#include <iostream>
#include <memory>

class OldPrinter
{
public:
    void oldPrint(std::string_view msg)
    {
        std::clog << "OldPrinter : " << msg << std::endl;
    }
};

class Printer
{
public:
    virtual void print(std::string_view msg) = 0;
    virtual ~Printer() = default;
};

class PrinterAdapter final : public Printer
{
    std::unique_ptr<OldPrinter> old_printer;

public:
    PrinterAdapter()
    {
        old_printer = std::make_unique<OldPrinter>();
    }

    void print(std::string_view msg) override
    {
        old_printer->oldPrint(msg);
    }
};

int main()
{
    auto printer_adapter = std::make_unique<PrinterAdapter>();
    printer_adapter->print("Hello Shiv.");

    return 0;
}