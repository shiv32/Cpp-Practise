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