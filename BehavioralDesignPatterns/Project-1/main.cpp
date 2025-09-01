#include <iostream>
#include <memory>

class Visitor
{
public:
    virtual void visit() = 0;
    virtual ~Visitor() = default;
};

class Student : public Visitor
{
    int rollNo{};
    std::string_view book;
    std::string_view status;

public:
    Student(int rollNo_, std::string_view book_, std::string_view status_)
        : rollNo(rollNo_),
          book(book_),
          status(status_)
    {
    }

    void visit() override
    {
        std::clog << rollNo << ": " << book << " " << status << std::endl;
    }
};

class BookRepair : public Visitor
{
    std::string_view book{};

public:
    BookRepair(std::string_view book_) : book(book_)
    {
    }

    void visit() override
    {
        std::clog << book << " repaired." << std::endl;
    }
};

class Library
{
public:
    virtual void accept(Visitor &v) = 0;
    virtual ~Library() = default;
};

class BookLibrary : public Library
{
public:
    void accept(Visitor &v) override
    {
        v.visit();
    }
};

void LibVisit(Library &lib, Visitor &v)
{
    lib.accept(v);
}

// smart ptr
void LibVisit(std::shared_ptr<Library> lib, std::unique_ptr<Visitor> v)
{
    lib->accept(*v);
}

int main()
{
    BookLibrary lib;
    Student st(123, "C++", "Issue"); //visitor
    LibVisit(lib, st);

    // smart ptr
    auto libPtr = std::make_shared<BookLibrary>();

    // visitors
    auto stPtr = std::make_unique<Student>(345, "data structure", "Return");
    auto stPtr2 = std::make_unique<Student>(567, "Java", "Issue");
    auto bookrepair = std::make_unique<BookRepair>("C++");

    LibVisit(libPtr, std::move(stPtr));
    LibVisit(libPtr, std::move(stPtr2));
    LibVisit(libPtr, std::move(bookrepair));

    return 0;
}