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

    std::vector<std::string> getItem()
    {
        return data;
    }
};

class InvoicePrint
{
public:
    static void print(std::unique_ptr<InvoiceData> invoiceData)
    {
        for (const auto &item : invoiceData->getItem())
        {
            std::clog << item << "\n";
        }
    }
};