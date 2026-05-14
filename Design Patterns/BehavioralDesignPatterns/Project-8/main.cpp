#include <iostream>
#include <memory>

//Class -----------------------------------
class Expression
{
public:
    virtual int interpret() = 0;
    virtual ~Expression() = default;
};

class Number : public Expression
{
    int number_{};

public:
    Number(const int &number);
    int interpret() override;
};

class Add : public Expression
{
    using expPtr = std::unique_ptr<Expression>;

    expPtr left_{}, right_{};

public:
    Add(expPtr left, expPtr right);
    int interpret() override;
};

//Definitions -------------------------
Number::Number(const int &number) : number_(number)
{
}

int Number::interpret()
{
    return number_;
}

Add::Add(expPtr left, expPtr right)
: left_(std::move(left)),
  right_(std::move(right))
{

}

int Add::interpret()
{
   return left_->interpret()+right_->interpret();
}

int main()
{

    auto add = std::make_unique<Add>(std::make_unique<Number>(3), std::make_unique<Number>(6));
    std::clog<<add->interpret()<<std::endl;

    return 0;
}
