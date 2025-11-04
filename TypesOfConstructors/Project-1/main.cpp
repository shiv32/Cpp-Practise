#include <iostream>
#include <string>

struct Test
{
    int x{};

    // default
    Test()
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    // parameter
    Test(int ix) : x(ix)
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    // copy
    Test(const Test &other) : x(other.x)
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    // move
    Test(Test &&other) noexcept : x(other.x)
    {
        other.x = 0;
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    // delegate
    Test(double d) : Test(static_cast<int>(d))
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    // explicit
    explicit Test(char c) : x(c)
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    // deleted
    Test(std::string) = delete;
    Test(const char *) = delete;
};

// aggregate(no ctor)
struct Test2
{
    int x, y;
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // default
    // Test a;

    // parameter
    //Test a1(5);

    // copy
    //Test a2 = a1;

    // move
    //Test a3 = std::move(a2);

    // delegate
    // Test(5.9);

    // explicit
    //Test a4('b');       //call explicit ctor
    //Test a4 = 'b';     //call implicit ctor

    // delete
    // Test("shiv");
    // Test a5 = "shiv";

    // Test2 t{5, 9};
    // std::clog << t.x << std::endl;
    // std::clog << t.y << std::endl;

    return 0;
}