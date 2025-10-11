#include <iostream>
#include <memory>

class Demo
{
    std::string m_objName;

public:
    Demo(std::string objName) : m_objName(std::move(objName))
    {
        std::clog << m_objName << " constructed." << std::endl;
    }

    ~Demo()
    {
        std::clog << m_objName << " destructed." << std::endl;
    }

    void greet()
    {
        std::clog << "Hello " << m_objName << std::endl;
    }
};

int main(int argc, char *argv[])
{
    // 1. unique pointer
    {
        std::unique_ptr<Demo> obj1 = std::make_unique<Demo>("obj1");
        obj1->greet();

        std::unique_ptr<Demo> obj2 = std::move(obj1);

        if (!obj1)
            std::clog << "obj1 moved its resources." << std::endl;

        obj2->greet();
    }

    std::clog << "---------------------" << std::endl;

    // 2. unique pointer custom deleter
    {
        auto deleter = [](Demo *p)
        {
            std::clog << "Custom deleter called." << std::endl;
            delete p;
        };

        std::unique_ptr<Demo, decltype(deleter)> obj3(new Demo("obj3"), deleter);

        obj3->greet();
    }

    std::clog << "main exit." << std::endl;
    
    return 0;
}