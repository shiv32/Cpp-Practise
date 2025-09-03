#include <iostream>
#include <memory>

#define TRACE std::clog << __PRETTY_FUNCTION__ << std::endl;

class Context;

class State
{
public:
    virtual void handle(Context &ctx) = 0;
    virtual ~State() = default;
};

class Context
{
    std::unique_ptr<State> state{};

public:
    Context(std::unique_ptr<State> st) : state(std::move(st)) {}
    void setState(std::unique_ptr<State> st) { state = std::move(st); }
    void request() { state->handle(*this); }
};

//-------- states ----------------------
class StateA : public State
{
public:
    void handle(Context &ctx) override;
};

class StateB : public State
{
public:
    void handle(Context &ctx) override;
};
//--------------------------------------

//------------ state handle -------------
void StateA::handle(Context &ctx)
{
    TRACE
    ctx.setState(std::make_unique<StateB>());
}

void StateB::handle(Context &ctx)
{
    TRACE
    ctx.setState(std::make_unique<StateA>());
}
//--------------------------------------

int main()
{
    // Context ctx(std::make_unique<StateA>());
    // ctx.request();
    // ctx.request();

    // smart ptr
    auto ctx2 = std::make_unique<Context>(std::make_unique<StateA>());
    ctx2->request();
    ctx2->request();

    return 0;
}