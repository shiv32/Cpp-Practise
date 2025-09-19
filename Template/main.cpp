#include <iostream>
#include <string>
#include <memory>

// funtion template
template <typename T>
T add(T a, T b)
{
    return a + b;
}

// class template
template <typename T>
class Box // primary template class
{
    T value_{};

public:
    Box(T value) : value_(value) {}
    void show()
    {
        std::clog << "value : " << value_ << std::endl;
    }
};

// template spcialization
template <>
class Box<std::string> // full specialization class for string
{
    std::string value_;

public:
    Box(std::string value) : value_(value) {}
    void show()
    {
        std::clog << "string value : " << value_ << std::endl;
    }
};

int main()
{
    // function template
    std::clog << add<int>(3, 5) << std::endl;
    std::clog << add(4.5, 6.7) << std::endl; // type deduce

    // class template
    Box<int> intBox(55);
    intBox.show();

    auto intBox2 = std::make_unique<Box<int>>(77);
    intBox2->show();

    // if specialization available then it will use it, otherewise primary template class will be used
    auto stringBox = std::make_unique<Box<std::string>>("shiv");
    stringBox->show();

    return 0;
}