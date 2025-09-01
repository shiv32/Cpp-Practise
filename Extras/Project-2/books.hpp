#pragma once
#include "library.hpp"
#include "visitor.hpp"
#include <iostream>

class Books final : public Library {
public:
    void accept(Visitor& vi) override {
        vi.visit(*this);
    }

    void itemGet() override {
        std::clog << "Book submit." << std::endl;
    }

    void itemGive() override {
        std::clog << "Book get." << std::endl;
    }
};
