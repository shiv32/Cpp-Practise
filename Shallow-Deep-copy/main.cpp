#include <iostream>
#include <cstring>
#include <memory>

class Prototype
{
public:
    virtual ~Prototype() = default;
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void print() const = 0;
};

class Data : public Prototype
{
    char *buffer;

public:
    Data(const char *text)
    {
        buffer = new char[std::strlen(text) + 1];
        std::strcpy(buffer, text);
    }

    Data(const Data &data, bool isShallow)
    {
        if (isShallow)
        {
            buffer = data.buffer;
        }
        else
        {
            buffer = new char[std::strlen(data.buffer) + 1];
            std::strcpy(buffer, data.buffer);
        }
    }

    std::unique_ptr<Prototype> clone() const override
    {
        return std::make_unique<Data>(*this, false);
    }

    void print() const override
    {
        std::clog << "Data: " << buffer << std::endl;
    }

    ~Data()
    {
        delete[] buffer;
    }
};

int main(int argc, char *agrv[])
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // stack object (auto lifetime).
    Data original("Hello shiv.");
    Data shallowCopy(original, true);
    auto deepCopy = original.clone();

    original.print();
    shallowCopy.print();
    deepCopy->print();

    //------------------
    // auto original2 = std::make_unique<Data>("Hello Shiv2");  //in stack --> heap
    // auto shallowCopy2 = std::make_unique<Data>(*original2, true); //in stack --> heap

    // original2->print();
    // shallowCopy2->print();

    //---------------------
    // Data *original3 = new Data("Hello shiv3"); //in stack --> heap
    // Data shallowCopy3(*original3, true); //in stack --> heap

    // shallowCopy3.print();

    // delete original3;
    // original3 = nullptr;

    return 0;
}