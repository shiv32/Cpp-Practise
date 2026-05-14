#include <iostream>
#include <memory>

class Library;

class Visitor
{
public:
    virtual void visit(Library &lib) = 0;
    virtual ~Visitor() = default;
};

class Student : public Visitor
{
    int rollNo{};
    std::string_view book;
    std::string_view status;

public:
    Student(int rollNo_, std::string_view book_, std::string_view status_);
    void visit(Library &lib) override;
};

class BookRepair : public Visitor
{
    std::string_view book{};

public:
    BookRepair(std::string_view book_);
    void visit(Library &lib) override;
};

class Library
{
public:
    virtual void accept(Visitor &v) = 0;
    virtual std::string libName() = 0;
    virtual ~Library() = default;
};

class BookLibrary : public Library
{
    std::string libname_{"Newton Library, 302, kailash road."};

public:
    void accept(Visitor &v) override;
    std::string libName() override;
};

class BookLibrary2 : public Library
{
    std::string libname_{"Subash Library, 455, meera road."};

public:
    void accept(Visitor &v) override;
    std::string libName() override;
};

//------------------- Definition -------------------------

Student::Student(int rollNo_, std::string_view book_, std::string_view status_)
    : rollNo(rollNo_),
      book(book_),
      status(status_)
{
}

void Student::visit(Library &lib)
{
    std::clog << "\n-----------------------\n";
    std::clog << lib.libName() << "\n";
    std::clog << rollNo << ": " << book << " " << status << std::endl;
}

BookRepair::BookRepair(std::string_view book_) : book(book_)
{
}

void BookRepair::visit(Library &lib)
{
    std::clog << "\n-----------------------\n";
    std::clog << lib.libName() << "\n";
    std::clog << book << ", repaired." << std::endl;
}

void BookLibrary::accept(Visitor &v)
{
    v.visit(*this);
}

std::string BookLibrary::libName()
{
    return libname_;
}

void BookLibrary2::accept(Visitor &v)
{
    v.visit(*this);
}

std::string BookLibrary2::libName()
{
    return libname_;
}

//--------------------interface------------------------
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
    BookLibrary lib; //visiting place
    Student stududent(123, "C++", ", Issue"); // visitor
    LibVisit(lib, stududent); //interface

    // smart ptr

    //visiting place
    auto libPtr = std::make_shared<BookLibrary>();
    auto libPtr2 = std::make_shared<BookLibrary2>();

    // visitors
    auto student1 = std::make_unique<Student>(345, "data structure", ", Return");
    auto student2 = std::make_unique<Student>(567, "Java", ", Issue");
    auto bookrepair = std::make_unique<BookRepair>("C++");

    //interface
    LibVisit(libPtr, std::move(student1));
    LibVisit(libPtr, std::move(student2));
    LibVisit(libPtr, std::move(bookrepair));

    student1 = std::make_unique<Student>(345, "data structure", ", Issue");
    LibVisit(libPtr2, std::move(student1));

    return 0;
}