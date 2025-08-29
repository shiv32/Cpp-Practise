#include <iostream>
#include <memory>

/*
    5. DIP - Dependency inversion principle
*/

class IMessageSender
{
public:
    virtual void send(std::string_view msg) = 0;
    virtual ~IMessageSender() = default;
};

class Email : public IMessageSender
{
public:
    void send(std::string_view msg) override
    {
        std::clog << "Email : " << msg << std::endl;
    }
};

class WhatsApp : public IMessageSender
{
public:
    void send(std::string_view msg) override
    {
        std::clog << "WhatsApp : " << msg << std::endl;
    }
};

class Notification
{
    std::unique_ptr<IMessageSender> sender{};

public:
    Notification(std::unique_ptr<IMessageSender> sender_) : sender(std::move(sender_)) {}
    void send(std::string_view msg)
    {
        sender->send(msg);
    };
};