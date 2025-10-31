#include <iostream>
#include <memory>

// Command interface
struct Command 
{
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Receiver
struct Light 
{
    void on()  { std::cout << "Light ON\n"; }
    void off() { std::cout << "Light OFF\n"; }
};

// Concrete Command
struct LightOnCommand : Command 
{
    Light& light;

    LightOnCommand(Light& l) : light(l) 
    {

    }

    void execute() override 
    { 
        light.on(); 
    }
};

// Invoker
struct Remote 
{
    std::unique_ptr<Command> cmd;

    void set(std::unique_ptr<Command> c) 
    { 
        cmd = std::move(c); 
    }

    void press() 
    { 
        if (cmd) 
            cmd->execute(); 
    }
};

// Client
int main() {

    Light light;
    Remote remote;
    
    remote.set(std::make_unique<LightOnCommand>(light));
    remote.press(); // Output: Light ON
}
