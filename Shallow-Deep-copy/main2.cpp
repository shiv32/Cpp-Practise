// smart pointer version

#include <iostream>
#include <memory>
#include <cstring>

class Prototype
{
public:
    ~Prototype() = default;
    virtual std::unique_ptr<Prototype> clone() = 0;
    virtual void print() = 0;
};

class Data : public Prototype
{
    std::shared_ptr<char[]> buffer;

public:
    Data(const char *text)
    {
        size_t length = std::strlen(text) + 1;
        buffer = std::shared_ptr<char[]>(new char[length], std::default_delete<char[]>());
        std::memcpy(buffer.get(), text, length);
    }

    Data(const Data &data, bool isShallow)
    {
        if (isShallow)
        {
            buffer = data.buffer;
        }
        else
        {
            size_t length = std::strlen(data.buffer.get()) + 1;
            buffer = std::shared_ptr<char[]>(new char[length], std::default_delete<char[]>());
            std::memcpy(buffer.get(), data.buffer.get(), length);
        }
    }

    std::unique_ptr<Prototype> clone() override
    {
        return std::make_unique<Data>(*this, false);
    }

    void print() override
    {
        std::clog << "data : " << buffer.get() << std::endl;
    }
};

int main(int argc, char *argv[])
{
    Data data("Hello shiv");
    Data shallowCopy(data, true);
    auto deepCopy = data.clone();

    data.print();
    shallowCopy.print();
    deepCopy->print();
}