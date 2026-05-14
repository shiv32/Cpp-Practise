#include <iostream>
#include <memory>

class Cpu
{
public:
    void start() { std::clog << "CPU started." << std::endl; }
};

class Memory
{
public:
    void load() { std::clog << "Memory loaded." << std::endl; }
};

class Hdd
{
public:
    void read() { std::clog << "Hdd read." << std::endl; }
};

class ComputerFacade
{
    Cpu cpu;
    Memory mem;
    Hdd hd;

public:
    void start()
    {
        cpu.start();
        mem.load();
        hd.read();
        std::clog << "Computer ready to use." << std::endl;
    }
};

int main()
{
    auto cf = std::unique_ptr<ComputerFacade>();
    cf->start();

    return 0;
}