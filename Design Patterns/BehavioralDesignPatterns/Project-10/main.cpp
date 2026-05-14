#include <iostream>
#include <memory>

// class & interface
class Handler
{
    using handlerPtr = std::unique_ptr<Handler>;

    handlerPtr next_{};

public:
    void setHandler(handlerPtr next);
    virtual void handle(int req);
};

class ConcreteHandler : public Handler
{
    int limit_{};

public:
    ConcreteHandler(int limit);
    void handle(int req) override;
};

// Definion

void Handler::setHandler(handlerPtr next)
{
    next_ = std::move(next);
}

void Handler::handle(int req)
{
    if (next_)
        next_->handle(req);
}

ConcreteHandler::ConcreteHandler(int limit) : limit_(limit)
{
}

void ConcreteHandler::handle(int req)
{
    if (req < limit_)
        std::clog << "req " << req << " handle at limit " << limit_ << std::endl;
    else
        Handler::handle(req);
}

int main()
{
    auto conHandle1 = std::make_unique<ConcreteHandler>(30);
    auto conHandle2 = std::make_unique<ConcreteHandler>(70);
    
    conHandle1->setHandler(std::move(conHandle2));

    conHandle1->handle(20);
    conHandle1->handle(50);

    return 0;
}