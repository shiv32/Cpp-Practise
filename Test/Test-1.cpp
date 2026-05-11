// rule of five

#include <iostream>
#include <cstring>

using namespace std;

#define TRACE cout << __PRETTY_FUNCTION__ << endl;

class Persion
{
    char *mname;

public:
    Persion(const char *name)
    {
        TRACE

        mname = new char[strlen(name) + 1];
        strcpy(mname, name);
    }

    ~Persion()
    {
        TRACE

        delete[] mname;
    }

    Persion(const Persion &other)
    {
        TRACE

        mname = new char[strlen(other.mname) + 1];
        strcpy(mname, other.mname);
    }

    Persion &operator=(const Persion &other)
    {
        TRACE

        // no self assignment
        if (this != &other)
        {
            delete[] mname;
            mname = new char[strlen(other.mname) + 1];
            strcpy(mname, other.mname);
        }

        return *this;
    }

    Persion(Persion &&other) noexcept
    {
        TRACE

        mname = other.mname;
        other.mname = nullptr;
    }

    Persion &operator=(Persion &&other) noexcept
    {
        TRACE

        // no self assingment
        if (this != &other)
        {
            delete[] mname;
            mname = other.mname;
            other.mname = nullptr;
        }

        return *this;
    }
};

int main(int arc, char *argv[])
{
    Persion p("shiv");

    // Persion p2(p); //copy ctor
    // Persion p3(move(p)); //move ctor

    Persion p4("test");
    // p4 = p; // copy assignment optr
    p4 = move(p); // move assignment optr

    return EXIT_SUCCESS;
}