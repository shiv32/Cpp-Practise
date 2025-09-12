#include <iostream>
#include <memory>

#define TRACE std::clog << __PRETTY_FUNCTION__ << std::endl;

// class------------------------

class Receiver;

class Command
{
protected:
    Receiver &receiver_;

public:
    Command(Receiver &receiver);
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class ConcreteCommand : public Command
{

public:
    using Command::Command;
    void execute() override;
};

class ConcreteCommand2 : public Command
{

public:
    using Command::Command;
    void execute() override;
};

class Receiver
{
public:
    virtual void action() = 0;
    virtual ~Receiver() = default;
};

class ConcreteReceiver : public Receiver
{
public:
    void action() override;
};

class ConcreteReceiver2 : public Receiver
{
public:
    void action() override;
};

using commandPtr = std::unique_ptr<Command>;

class Invoker
{
    commandPtr command_{};

public:
    void setCommand(commandPtr command);
    void run();
};

// Definition -----------------------------
Command::Command(Receiver &receiver) : receiver_(receiver)
{
}

void ConcreteCommand::execute()
{
    receiver_.action();
}

void ConcreteCommand2::execute()
{
    receiver_.action();
}

void ConcreteReceiver::action()
{
    TRACE
}

void ConcreteReceiver2::action()
{
    TRACE
}

void Invoker::setCommand(commandPtr command)
{
    command_ = std::move(command);
}

void Invoker::run()
{
    if (command_)
    {
        command_->execute();
    }
}

int main()
{
    ConcreteReceiver conreceiver;
    ConcreteReceiver2 conreceiver2;

    auto conCommand = std::make_unique<ConcreteCommand>(conreceiver);
    auto conCommand2 = std::make_unique<ConcreteCommand2>(conreceiver2);

    auto invoker = std::make_shared<Invoker>();

    invoker->setCommand(std::move(conCommand));
    invoker->run();

    invoker->setCommand(std::move(conCommand2));
    invoker->run();

    return 0;
}