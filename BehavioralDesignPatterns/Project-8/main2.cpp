#include <iostream>

struct Expr 
{
     virtual int interpret() = 0; 
     virtual ~Expr() = default; 
};

struct Num : Expr 
{ 
    int v; 

    Num(int x):v(x)
    {
    } 
    
    int interpret() override 
    { 
        return v;   //grammer
    } 
};

struct Add : Expr 
{
    Expr *l, *r;

    Add(Expr* a, Expr* b):l(a),r(b)
    {
    }

    int interpret() override 
    { 
        return l->interpret() + r->interpret(); //grammer
    }
};

int main() 
{
    Num n1(2), n2(3);
    Add sum(&n1, &n2);

    std::cout << sum.interpret(); // Output: 5
}
