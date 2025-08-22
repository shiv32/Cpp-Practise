#include <iostream>
#include <cstring>
#include <memory>
#include <string>

#define TRACE std::clog << __PRETTY_FUNCTION__ << std::endl;

namespace rawPtr
{
    class Persion
    {
        char *name;

    public:
        Persion(const char *mname)
        {
            name = new char[strlen(mname) + 1];
            strcpy(name, mname);
            std::clog << __PRETTY_FUNCTION__ << std::endl;
        }

        // dtor
        ~Persion()
        {
            delete[] name;
            std::clog << __PRETTY_FUNCTION__ << std::endl;
        }

        // copy ctor
        Persion(const Persion &other)
        {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            std::clog << __PRETTY_FUNCTION__ << std::endl;
        }

        // copy assingment
        Persion &operator=(const Persion &other)
        {
            if (this != &other)
            {
                delete[] name;
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }

            std::clog << __PRETTY_FUNCTION__ << std::endl;
            return *this;
        }

        // move ctor
        Persion(Persion &&other) noexcept
        {
            name = other.name;
            other.name = nullptr;
            std::clog << __PRETTY_FUNCTION__ << std::endl;
        }

        // move assignment
        Persion &operator=(Persion &&other) noexcept
        {
            if (this != &other)
            {
                delete[] name;
                name = other.name;
                other.name = nullptr;
            }
            std::clog << __PRETTY_FUNCTION__ << std::endl;
            return *this;
        }

        void greet()
        {
            std::clog << "Hello " << name << std::endl;
        }
    };

}

namespace smartPtr
{
    class Persion
    {
        std::unique_ptr<std::string> name;

    public:
        Persion(const std::string &mname) : name(std::make_unique<std::string>(mname))
        {
            TRACE;
        }

        ~Persion()
        {
            TRACE;
        }

        Persion(const Persion &other) : name(std::make_unique<std::string>(*other.name))
        {
            TRACE;
        }

        Persion &operator=(const Persion &other)
        {
            if (this != &other)
            {
                name = std::make_unique<std::string>(*other.name);
            }
            TRACE;
            return *this;
        }

        Persion(Persion &&other) noexcept = default;
        Persion &operator=(Persion &&) noexcept = default;

        void greet()
        {
            std::clog << "Hello " << *name << std::endl;
        }
    };
}

int main()
{
    //using namespace rawPtr;
    using namespace smartPtr;

    Persion a("shiv");
    Persion b = a;            // copy ctor
    Persion c = std::move(a); // move ctor

    Persion d("test");

    d = b;            // copy assignment
    d = std::move(c); // move assignment

    d.greet();

    return 0;
}