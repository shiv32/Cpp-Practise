#include <iostream>
#include <memory>

class Button
{
public:
    virtual void draw() = 0;
    virtual ~Button() = default;
};

class winButton final : public Button
{
public:
    void draw() override
    {
        std::clog << "win button draw." << std::endl;
    }
};

class LinuxButton final : public Button
{
public:
    void draw() override
    {
        std::clog << "Linux button draw." << std::endl;
    }
};

class GUIFactory
{
public:
    virtual std::unique_ptr<Button> drawButton() = 0;
    virtual ~GUIFactory() = default;
};

class WinFactory final : public GUIFactory
{
public:
    std::unique_ptr<Button> drawButton() override
    {
        return std::make_unique<winButton>();
    }
};

class LinuxFactory final : public GUIFactory
{
public:
    std::unique_ptr<Button> drawButton() override
    {
        return std::make_unique<LinuxButton>();
    }
};

void buildGUI(std::unique_ptr<GUIFactory> gui)
{
    gui->drawButton()->draw();
}

enum class OS
{
    WINDOW,
    MAC,
    LINUX
};

int main()
{
    OS osname = OS::LINUX;

    switch (osname)
    {
    case OS::WINDOW:
        buildGUI(std::make_unique<WinFactory>());
        break;
    case OS::LINUX:
        buildGUI(std::make_unique<LinuxFactory>());
        break;
    case OS::MAC:
    default:
        std::clog << "OS not found !" << std::endl;
        break;
    }

    return 0;
}