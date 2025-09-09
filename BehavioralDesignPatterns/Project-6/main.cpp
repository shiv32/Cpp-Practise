#include <iostream>
#include <memory>
#include <vector>

class Mediator;
class Colleague;
// using CollgPtr = std::shared_ptr<Colleague>;
using CollgPtr = Colleague *;

//-------------------------------------------------------------
class Colleague
{
protected:
    Mediator &med_;
    std::string_view name_{};

public:
    Colleague(std::string_view name, Mediator &med);
    virtual void send(const std::string &msg) = 0;
    virtual void receieve(const std::string &msg) = 0;
    virtual ~Colleague() = default;
};

class ConcreteColl : public Colleague, public std::enable_shared_from_this<ConcreteColl>
{
public:
    using Colleague::Colleague;
    void send(const std::string &msg) override;
    void receieve(const std::string &msg) override;
};

class Mediator
{
    std::vector<CollgPtr> coll_{};

public:
    void add(CollgPtr coll);
    void distribute(CollgPtr coll, std::string_view msg);
};

//-----------------------
Colleague::Colleague(std::string_view name, Mediator &med) : med_(med), name_(name)
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;
}

void ConcreteColl::send(const std::string &msg)
{
    // med_.distribute(std::make_shared<ConcreteColl>(*this), msg); //not work
    // med_.distribute(shared_from_this(), msg);
    med_.distribute(this, msg);
}

void ConcreteColl::receieve(const std::string &msg)
{
    std::clog << name_ << " receieved " << msg << std::endl;
}

void Mediator::add(CollgPtr coll)
{
    coll_.emplace_back(coll);
}

void Mediator::distribute(CollgPtr coll, std::string_view msg)
{
    for (const auto &cl : coll_)
    {
        if (cl != coll)
        {
            cl->receieve(msg.data());
        }
    }
}

int main()
{
    //-----------------------------------------------
    // auto med = std::make_shared<Mediator>();

    // auto concl1 = std::make_shared<ConcreteColl>("emp1", *med.get());
    // auto concl2 = std::make_shared<ConcreteColl>("emp2", *med.get());

    // med->add(concl1);
    // med->add(concl2);

    // concl1->send("Hello Shiv.");
    // concl2->send("Hello Manoj.");
    //---------------------------------------------
    // Mediator med;

    // auto concl1 = std::make_shared<ConcreteColl>("emp1", med);
    // auto concl2 = std::make_shared<ConcreteColl>("emp2", med);

    // med.add(concl1);
    // med.add(concl2);

    // concl1->send("Hello Shiv.");

    //--------------------------------------------
    Mediator med;
    ConcreteColl concl1("emp1", med), concl2("emp2", med);

    med.add(&concl1);
    med.add(&concl2);

    concl1.send("Hello Shiv.");

    return 0;
}