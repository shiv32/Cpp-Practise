#include <iostream>
#include <memory>
#include <unordered_map>

class Glyph
{
    char symbol;

public:
    Glyph(char c) : symbol(c) {};
    void draw(int x, int y)
    {
        std::cout << "drawing " << symbol << " at (" << x << "," << y << ")" << std::endl;
    }
};

class GlyphFactory
{
    std::unordered_map<char, std::shared_ptr<Glyph>> pools;

public:
    std::shared_ptr<Glyph> get(char c)
    {
        if (!pools[c])
            pools[c] = std::make_shared<Glyph>(c);

        return pools[c];
    }

    void poolsSize()
    {
        std::clog << "pools size : " << pools.size() << std::endl;
    }
};

int main()
{
    // auto gl = std::make_shared<Glyph>('A');
    // gl->draw(6,8);
    // gl->draw(3,7);

    //-------------------------------------------
    GlyphFactory gf;

    gf.poolsSize();

    auto gfA = gf.get('A');
    auto gfB = gf.get('B');

    gfA->draw(1, 2);
    gfB->draw(4, 6);

    gf.get('A')->draw(8, 3);

    gf.poolsSize();

    return 0;
}