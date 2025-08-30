#pragma once
#include "library.hpp"
#include "visitor.hpp"
#include <iostream>

class Magazine final : public Library {
public:
    void accept(Visitor& vi) override {
        vi.visit(*this);
    }

    void itemGet() override {
        std::clog << "Magazine submit." << std::endl;
    }

    void itemGive() override {
        std::clog << "Magazine get." << std::endl;
    }
};
