#include <iostream>

class Singleton
{
private:
    Singleton() { std::clog << __PRETTY_FUNCTION__ << std::endl; }
    ~Singleton() { std::clog << __PRETTY_FUNCTION__ << std::endl; }

public:
    static Singleton &instance()
    {
        static Singleton obj;
        return obj;
    }

    void logger(std::string_view msg)
    {
        std::clog << "[Log] : " << msg << std::endl;
    }
};

int main()
{
    Singleton::instance().logger("main 1 call ");
    Singleton::instance().logger("main 2 call ");
    Singleton::instance().logger("main 3 call ");
    Singleton::instance().logger("main 4 call ");

    return 0;
}
