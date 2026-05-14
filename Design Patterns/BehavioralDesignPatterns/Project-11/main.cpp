#include <iostream>
#include <memory>

// class
class Operation
{
public:
    virtual int doOp(int a, int b) = 0;
    virtual ~Operation() = default;
};

class AddOp : public Operation
{
public:
    int doOp(int a, int b) override;
};

class MinusOp : public Operation
{
public:
    int doOp(int a, int b) override;
};

using operationPtr = std::unique_ptr<Operation>;

class OperationStratgy
{
    operationPtr operation_{};

public:
    OperationStratgy(operationPtr operation);
    int execute(int a, int b);
};

// Definition

int AddOp::doOp(int a, int b)
{
    return a + b;
}

int MinusOp::doOp(int a, int b)
{
    return (a - b);
}

OperationStratgy::OperationStratgy(operationPtr operation)
    : operation_(std::move(operation))
{
}

int OperationStratgy::execute(int a, int b)
{
    return operation_->doOp(a, b);
}

void doOperation(std::unique_ptr<OperationStratgy> opStratgy, int a, int b)
{
    auto value = opStratgy->execute(a, b);
    std::clog << value << std::endl;
}

int main()
{
    // strategy
    auto addOp = std::make_unique<AddOp>();
    auto minOp = std::make_unique<MinusOp>();

    // auto opStratgy = std::make_unique<OperationStratgy>(std::move(addOp));
    // auto value = opStratgy->execute(3, 6);
    // std::clog << value << std::endl;

    doOperation(std::make_unique<OperationStratgy>(std::move(addOp)), 8, 5);
    doOperation(std::make_unique<OperationStratgy>(std::move(minOp)), 6, 5);

    return 0;
}