#include <iostream>
#include "common.hpp"

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

    // 5. DIP
    std::clog << "5. DIP" << std::endl;

    auto email = std::make_unique<Notification>(std::move(std::make_unique<Email>()));
    email->send("Hello email");

    auto whatsapp = std::make_unique<Notification>(std::move(std::make_unique<WhatsApp>()));
    whatsapp->send("Hello whatsapp");

    return 0;
}