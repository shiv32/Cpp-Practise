#include <iostream>
#include <memory>

class Image
{
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

class RealImage final : public Image
{
private:
    std::string filename{};

public:
    RealImage(std::string flname) : filename(std::move(flname))
    {
        std::clog << "Loading " << filename << std::endl;
    }

    void display() override
    {
        std::clog << "Display " << filename << std::endl;
    }
};

class ProxyImage final : Image
{
private:
    std::string filename{};
    std::unique_ptr<RealImage> ri;

public:
    ProxyImage(std::string flname) : filename(std::move(flname)) {};

    void display() override
    {
        if (!ri)
            ri = std::make_unique<RealImage>(filename);

        ri->display();
    }
};

int main()
{

    RealImage ri("shiv.png");
    ri.display();
    ri.display();

    ProxyImage pi("shiv2.png");
    pi.display(); // load
    pi.display(); // cache

    return 0;
}