#include <iostream>
#include <memory>

class DrawingApi
{
public:
    virtual void drawCircle(int x, int y, int r) = 0;
    virtual ~DrawingApi() = default;
};

class DrawingApi1 final : public DrawingApi
{
public:
    void drawCircle(int x, int y, int r) override
    {
        std::clog << "Api1.cirlce at (" << x << "," << y << ") " << "radius : " << r << std::endl;
    }
};

class DrawingApi2 final : public DrawingApi
{
public:
    void drawCircle(int x, int y, int r) override
    {
        std::clog << "Api2.cirlce at (" << x << "," << y << ") " << "radius : " << r << std::endl;
    }
};

// Bridge
class Shape
{
protected:
    std::unique_ptr<DrawingApi> dapi;

public:
    Shape(std::unique_ptr<DrawingApi> da) : dapi(std::move(da)) 
    {

    }
    
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class DrawCircle final : public Shape
{
    int x, y, r;

public:
    DrawCircle(int _x, int _y, int _r, std::unique_ptr<DrawingApi> da)
        : Shape(std::move(da)),
          x(_x),
          y(_y),
          r(_r)
    {
    }

    void draw() override
    {
        dapi->drawCircle(x, y, r);
    }
};

int main()
{
    auto da1 = std::make_unique<DrawingApi1>();
    auto da2 = std::make_unique<DrawingApi2>();

    auto dc1 = std::make_unique<DrawCircle>(2, 5, 3, std::move(da1));
    auto dc2 = std::make_unique<DrawCircle>(8, 4, 9, std::move(da2));

    dc1->draw();
    dc2->draw();

    return 0;
}