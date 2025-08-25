#include <iostream>
#include <memory>
#include <vector>

class Graphic
{
public:
    virtual void draw() = 0;
    virtual ~Graphic() = default;
};

class Line : public Graphic
{
public:
    void draw() override
    {
        std::clog << "draw line" << std::endl;
    }
};

class Circle : public Graphic
{
public:
    void draw() override
    {
        std::clog << "draw circle" << std::endl;
    }
};

class Canvas : public Graphic
{
    std::vector<std::unique_ptr<Graphic>> graphic;

public:
    void add(std::unique_ptr<Graphic> gr)
    {
        graphic.emplace_back(std::move(gr));
    }

    void draw() override
    {
        std::clog << "Canvas : " << std::endl;
        for (const auto &g : graphic)
        {
            g->draw();
        }
    }
};

int main()
{
    auto line = std::make_unique<Line>();
    auto circle = std::make_unique<Circle>();
    auto canvas = std::make_unique<Canvas>();

    canvas->add(std::move(line));
    canvas->add(std::move(circle));

    canvas->draw();

    return 0;
}