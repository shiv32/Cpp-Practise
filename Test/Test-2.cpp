#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

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

    void removeItem(std::string_view item)
    {
        data.erase(std::remove(data.begin(), data.end(), item.data()), data.end());
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

int main(int argc, char *argv[])
{
    auto id = make_unique<InvoiceData>();

    id->addItem("ob1");
    id->addItem("ob2");
    id->addItem("ob3");
    id->removeItem("ob2");

    InvoicePrint ip;
    ip.print(move(id));

    return EXIT_SUCCESS;
}