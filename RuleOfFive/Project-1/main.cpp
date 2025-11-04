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
            TRACE;

            name = new char[strlen(mname) + 1];
            strcpy(name, mname);
        }

        // dtor
        ~Persion()
        {
            TRACE;

            delete[] name;
        }

        // copy ctor
        Persion(const Persion &other)
        {
            TRACE;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }

        // copy assingment
        Persion &operator=(const Persion &other)
        {
            TRACE;

            if (this != &other)
            {
                delete[] name;
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }

            return *this;
        }

        // move ctor
        Persion(Persion &&other) noexcept
        {
            TRACE;

            name = other.name;
            other.name = nullptr;
        }

        // move assignment
        Persion &operator=(Persion &&other) noexcept
        {
            TRACE;

            if (this != &other)
            {
                delete[] name;
                name = other.name;
                other.name = nullptr;
            }

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
            TRACE;

            if (this != &other)
            {
                name = std::make_unique<std::string>(*other.name);
            }

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
    using namespace rawPtr;
    // using namespace smartPtr;

    Persion a("shiv");
    Persion b = a;            // copy ctor
    Persion c = std::move(a); // move ctor

    Persion d("test");

    d = b;            // copy assignment
    d = std::move(c); // move assignment

    d.greet();

    return 0;
}