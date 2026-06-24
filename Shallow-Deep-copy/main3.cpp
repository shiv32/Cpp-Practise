
#include <iostream>
using namespace std;

namespace shallow
{
    /*
        Copies only the pointer/address.
        Both objects share the same memory.
        Problem:
            Same memory shared
            Can cause double delete/crash
    */
    class Demo
    {
    public:
        int *data;

        Demo(int value)
        {
            data = new int(value);
        }

        // Shallow copy
        Demo(const Demo &other)
        {
            data = other.data;
        }

        ~Demo()
        {
            delete data;
        }
    };
}

namespace deep
{
    /*
        Copies actual value into new memory.
        Each object has separate memory.
    */
    class Demo
    {
    public:
        int *data;

        Demo(int value)
        {
            data = new int(value);
        }

        // Deep copy
        Demo(const Demo &other)
        {
            data = new int(*other.data);
        }

        ~Demo()
        {
            delete data;
        }
    };
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // shallow
    using namespace shallow;

    Demo a(10);
    Demo b = a;

    *b.data = 50;

    cout << *a.data << endl; // 50
    cout << *b.data << endl; // 50

    // deep-------------------------------------
    // using namespace deep;

    // Demo a(10);
    // Demo b = a;

    // *b.data = 50;

    // cout << *a.data << endl; // 10
    // cout << *b.data << endl; // 50
}