#include <iostream>
#include <memory>

class Widget
{
public:
    virtual void draw() = 0;
    virtual ~Widget() = default;
};

class TextField final : public Widget
{
public:
    void draw() override
    {
        std::clog << "TextField" << std::endl;
    }
};

class BorderDecoration final : public Widget
{
    std::unique_ptr<Widget> wid{};

public:
    BorderDecoration(std::unique_ptr<Widget> wd) : wid(std::move(wd)) {}
    void draw() override
    {
        wid->draw();
        std::clog << "  Border" << std::endl;
    }
};

int main()
{
    auto wid = std::make_unique<TextField>();
    wid->draw();

    auto widd = std::make_unique<BorderDecoration>(std::make_unique<TextField>());
    widd->draw();

    return 0;
}