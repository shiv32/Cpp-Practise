#include <iostream>
#include <memory>

class House
{
public:
    std::string wall, roof;
    void show() { std::clog << "House with " << wall << " wall and " << roof << " roof." << std::endl; }
};

class HouseBuilder
{
public:
    std::unique_ptr<House> house{};
    HouseBuilder() : house(std::make_unique<House>()) {};
    virtual HouseBuilder &buildWall() = 0;
    virtual HouseBuilder &buildRoof() = 0;
    std::unique_ptr<House> getHouse() { return std::move(house); }
    virtual ~HouseBuilder() = default;
};

class WoodenHouse final : public HouseBuilder
{
public:
    HouseBuilder &buildWall() override
    {
        house->wall = "wooden";
        return *this;
    }
    HouseBuilder &buildRoof() override
    {
        house->roof = "wooden";
        return *this;
    }
};

class StoneHouse final : public HouseBuilder
{
public:
    HouseBuilder &buildWall() override
    {
        house->wall = "Stone";
        return *this;
    }
    HouseBuilder &buildRoof() override
    {
        house->roof = "Stone";
        return *this;
    }
};

class Engineer
{
public:
    std::unique_ptr<House> construct(std::unique_ptr<HouseBuilder> hb)
    {
        return std::move(hb->buildWall().buildRoof().getHouse());
    }
};

enum class HouseEnum
{
    WOOD,
    STONE,
    CEMENT
};

int main()
{
    auto wh = std::make_unique<WoodenHouse>();
    auto sh = std::make_unique<StoneHouse>();
    Engineer en;
    HouseEnum hs = HouseEnum::CEMENT;

    switch (hs)
    {
    case HouseEnum::WOOD:
        en.construct(std::move(wh))->show();
        break;
    case HouseEnum::STONE:
        en.construct(std::move(sh))->show();
        break;
    default:
        std::clog << "House not build !" << std::endl;
        break;
    }

    return 0;
}