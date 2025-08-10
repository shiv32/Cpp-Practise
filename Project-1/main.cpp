#include <iostream>
#include <memory>

class Product
{
public:
    virtual void productName() = 0;
    virtual ~Product() = default;
};

class ProductA final : public Product
{
public:
    void productName() override
    {
        std::clog << "Product A" << std::endl;
    }
};

class ProductB final : public Product
{
public:
    void productName() override
    {
        std::clog << "Product B" << std::endl;
    }
};

class Creator
{
public:
    virtual std::unique_ptr<Product> createProduct() = 0;
    virtual ~Creator() = default;
};

class CreatorA final : public Creator
{
public:
    std::unique_ptr<Product> createProduct() override
    {
        return std::make_unique<ProductA>();
    }
};

class CreatorB final : public Creator
{
public:
    std::unique_ptr<Product> createProduct()
    {
        return std::make_unique<ProductB>();
    }
};

void factory(std::unique_ptr<Creator> crtr)
{
    crtr->createProduct()->productName();
}

enum class ProductName
{
    PRODUCTA,
    PRODUCTB,
    PRODUCTC
};

int main()
{

    // auto creator = std::make_unique<CreatorA>();
    // auto product = creator->createProduct();
    // product->productName();

    // auto creator2 = std::make_unique<CreatorB>();
    // auto product2 = creator2->createProduct();
    // product2->productName();

    ProductName name = ProductName::PRODUCTB;

    switch (name)
    {
    case ProductName::PRODUCTA:
        factory(std::make_unique<CreatorA>());
        break;
    case ProductName::PRODUCTB:
        factory(std::make_unique<CreatorB>());
    default:
        break;
    }

    return 0;
}
