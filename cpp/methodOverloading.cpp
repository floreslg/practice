#include<assert.h>


class Base
{
public:
    virtual int method() = 0;
};


class Derived1: public Base
{
public:
    int method();
};


class Derived2: public Base
{
public:
    int method();
};


int main()
{
    Derived1 derived1;
    Derived2 derived2;

    assert(derived1.method() != derived2.method());
}

int Derived1::method()
{
    return 1;
}

int Derived2::method()
{
    return 2;
}