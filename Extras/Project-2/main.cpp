#include <iostream>
#include <memory>
#include "concrete_visitors.hpp"

void executeVisit(std::shared_ptr<Library> lib, std::shared_ptr<Visitor> vi)
{
    lib->accept(*vi);
}

int main()
{
    // Create elements
    auto book = std::make_shared<Books>();
    auto magazine = std::make_shared<Magazine>();

    // Create visitors
    auto student = std::make_shared<Student>();
    auto librarian = std::make_shared<Librarian>();

    // Demonstrate visitor pattern
    executeVisit(book, student);
    executeVisit(book, librarian);
    executeVisit(magazine, student);
    executeVisit(magazine, librarian);

    return 0;
}