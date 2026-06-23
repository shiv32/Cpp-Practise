#include <iostream>
#include "common.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // 1. SRP
    std::clog << "1. SRP" << "\n";
    auto invoiceData = std::make_unique<srp::InvoiceData>();
    invoiceData->addItem("Book");
    invoiceData->addItem("Pen");
    invoiceData->addItem("paper");
    invoiceData->removeItem("Pen");
    srp::InvoicePrint::print(std::move(invoiceData));

    // 2. open-close
    std::clog << "2. open-close" << "\n";
    std::vector<std::unique_ptr<ocp::Shape>> shape;
    shape.push_back(std::make_unique<ocp::Circle>(2));
    shape.push_back(std::make_unique<ocp::Rectangle>(5, 6));
    std::clog << "total area : " << ocp::totalArea(shape) << "\n";

    // 3.LSP
    std::clog << "3. LSP" << "\n";
    lsp::BirdFly(std::move(std::make_unique<lsp::Sparrow>()));
    lsp::BirdFly(std::move(std::make_unique<lsp::Crow>()));

    // 4. ISP
    std::clog << "4. ISP" << "\n";
    isp::Print(std::move(std::make_unique<isp::SimplePrinter>()));
    // isp::Scan(std::move(std::make_unique<isp::SimplePrinter>())); //compile error
    isp::Print(std::move(std::make_unique<isp::SmartPrinter>()));
    isp::Scan(std::move(std::make_unique<isp::SmartPrinter>()));

    // 5. DIP
    std::clog << "5. DIP" << std::endl;

    auto email = std::make_unique<dip::Notification>(std::move(std::make_unique<dip::Email>()));
    email->send("Hello email");

    auto whatsapp = std::make_unique<dip::Notification>(std::move(std::make_unique<dip::WhatsApp>()));
    whatsapp->send("Hello whatsapp");

    return 0;
}