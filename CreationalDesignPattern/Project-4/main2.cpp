#include <iostream>
#include <memory>

class House
{
    std::string m_wall{}, m_roof{};

public:
    const std::string &getWall()
    {
        return m_wall;
    }

    void setWall(std::string_view wall)
    {
        m_wall = wall.data();
    }

    const std::string &getRoof()
    {
        return m_roof;
    }

    void setRoof(std::string_view roof)
    {
        m_roof = roof.data();
    }

    void show() { std::clog << "House with " << getWall() << " wall and " << getRoof() << " roof." << std::endl; }
};

class HouseBuilder
{
    std::shared_ptr<House> house{};

public:
    HouseBuilder() : house(std::make_shared<House>()) 
    {
    };

    virtual HouseBuilder &buildWall() = 0;
    virtual HouseBuilder &buildRoof() = 0;

    std::shared_ptr<House> getHouse()
    {
        return house;
    }

    virtual ~HouseBuilder() = default;
};

class WoodenHouse final : public HouseBuilder
{
public:
    HouseBuilder &buildWall() override
    {
        getHouse()->setWall("wooden");
        return *this;
    }

    HouseBuilder &buildRoof() override
    {
        getHouse()->setRoof("wooden");
        return *this;
    }
};

class StoneHouse final : public HouseBuilder
{
public:
    HouseBuilder &buildWall() override
    {
        getHouse()->setWall("Stone");
        return *this;
    }

    HouseBuilder &buildRoof() override
    {
        getHouse()->setRoof("Stone");
        return *this;
    }
};

class Engineer
{
public:
    std::shared_ptr<House> construct(std::unique_ptr<HouseBuilder> hb)
    {
        return hb->buildWall().buildRoof().getHouse();
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

    // HouseEnum hs = HouseEnum::CEMENT;
    HouseEnum hs = HouseEnum::STONE;
    // HouseEnum hs = HouseEnum::WOOD;

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