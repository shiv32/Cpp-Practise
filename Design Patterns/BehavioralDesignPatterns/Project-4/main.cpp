#include <iostream>
#include <vector>
#include <memory>

class Observer
{
public:
    virtual void update(int value) = 0;
    virtual ~Observer() = default;
};

class ConcreretObserver : public Observer
{
    std::string name{};

public:
    ConcreretObserver(std::string name_) : name(std::move(name_))
    {
    }
    
    void update(int value) override
    {
        std::clog << name << " oberver got " << value << std::endl;
    }
};

class Subject
{
    std::vector<std::unique_ptr<Observer>> observer{};
    int value{};

public:
    void attach(std::unique_ptr<Observer> ob)
    {
        observer.push_back(std::move(ob));
    }

    void setValue(int value_)
    {
        value = value_;

        for (const auto &ob : observer)
        {
            ob->update(value);
        }
    }
};

int main()
{
    auto obs1 = std::make_unique<ConcreretObserver>("Obs1");
    auto obs2 = std::make_unique<ConcreretObserver>("Obs2");

    auto subject = std::make_unique<Subject>();

    subject->attach(std::move(obs1));
    subject->attach(std::move(obs2));

    subject->setValue(109);
    subject->setValue(112);

    return 0;
}