#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

/*
1. Single responsibility principle
*/

namespace srp
{
    class InvoiceData
    {
    private:
        std::vector<std::string> data;

    public:
        void addItem(std::string_view item)
        {
            data.push_back(item.data());
        }

        void removeItem(std::string_view item)
        {
            data.erase(std::remove(data.begin(), data.end(), item.data()), data.end());
        }

        std::vector<std::string> getItems()
        {
            return data;
        }
    };

    class InvoicePrint
    {
    public:
        static void print(std::unique_ptr<InvoiceData> invoiceData)
        {
            for (const auto &item : invoiceData->getItems())
            {
                std::clog << item << "\n";
            }
        }
    };
}
