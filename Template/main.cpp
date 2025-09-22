#include <iostream>
#include <string>
#include <memory>

// 1. funtion template
template <typename T>
T add(T a, T b)
{
    return a + b;
}

// 2. class template
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

// 3. template spcialization
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

// 4. Non-type template paramter
template <typename T, int size>
class Array
{
    T data[size]{};

public:
    void set(int index, T value)
    {
        data[index] = value;
    }

    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            std::clog << "value : " << data[i]<<", ";
        }

        // for (auto const value_ : data)
        // {
        //     std::clog << "value : " << value_ << ", ";
        // }

        std::clog << std::endl;
    }
};

// 5. template with auto (C++ 17 deduction guide)
template<typename T1, typename T2>
auto multiply(T1 first, T2 second)
{
     return first*second;
}

int main()
{
    // 1. function template
    std::clog << add<int>(3, 5) << std::endl;
    std::clog << add(4.5, 6.7) << std::endl; // type deduce

    std::cout << "----------" << std::endl;

    // 2. class template
    Box<int> intBox(55);
    intBox.show();

    auto intBox2 = std::make_unique<Box<int>>(77);
    intBox2->show();

    std::cout << "----------" << std::endl;

    // 3. specialization
    // if specialization available then it will use it, otherewise primary template class will be used
    auto stringBox = std::make_unique<Box<std::string>>("shiv");
    stringBox->show();

    std::cout << "-----------" << std::endl;

    // 4. Non-type template parameter
    Array<int, 6> array;

    for (int i = 0; i < 6; ++i)
    {
        array.set(i, i * 10);
    }

    array.print();

    std::cout<<"--------------"<<std::endl;

    //5. template with auto
    std::clog<<"mutltiply : "<<multiply(3, 6.4)<<std::endl;
    std::clog<<"mutltiply : "<<multiply(4.5, 6)<<std::endl;

    return 0;
}