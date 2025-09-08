#include <iostream>
#include <memory>

class Memento
{
    std::string state_{};

public:
    Memento(std::string state) : state_(std::move(state))
    {
    }

    std::string getState() const
    {
        return state_;
    }
};

class States
{
    std::string state_{};

public:
    void setState(const std::string &state)
    {
        state_ = state;
    }

    std::string getState() const
    {
        return state_;
    }

    std::unique_ptr<Memento> save()
    {
        return std::make_unique<Memento>(state_);
    }

    void restore(std::unique_ptr<Memento> meme)
    {
        state_ = meme->getState();
    }
};

int main()
{
    auto state = std::make_unique<States>();

    state->setState("state 1");
    std::clog<<state->getState()<<"\n";
    auto state1 = state->save();

    state->setState("state 2");
    std::clog<<state->getState()<<"\n";

    state->restore(std::move(state1));
    std::clog<<state->getState()<<"\n";
 
    return 0;
}