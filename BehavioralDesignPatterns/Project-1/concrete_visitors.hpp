#pragma once
#include "visitor.hpp"
#include "books.hpp"
#include "magazine.hpp"
#include <iostream>

class Student final : public Visitor {
public:
    void visit(Books& book) override {
        std::clog << "Student visits Books section\n";
        book.itemGive();
        book.itemGet();
    }

    void visit(Magazine& magazine) override {
        std::clog << "Student visits Magazine section\n";
        magazine.itemGive();
        magazine.itemGet();
    }
};

class Librarian final : public Visitor {
public:
    void visit(Books& book) override {
        std::clog << "Librarian visits Books section\n";
        book.itemGet();
        book.itemGive();
    }

    void visit(Magazine& magazine) override {
        std::clog << "Librarian visits Magazine section\n";
        magazine.itemGet();
        magazine.itemGive();
    }
};
