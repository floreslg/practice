#include<iostream>

using namespace std;


class Base
{
public:
    Base();
    ~Base();
};


class Derived : public Base
{
public:
    Derived();
    ~Derived();
};

class VirtBase
{
public:
    VirtBase();
    virtual ~VirtBase();
};


class VirtDerived : public VirtBase
{
public:
    VirtDerived();
    ~VirtDerived();
};

int main()
{
    Base* base = new Base();
    delete base;
    cout << "--------------------" << endl;

    Base* derivedA = new Derived();
    delete derivedA;
    cout << "--------------------" << endl;

    Derived* derivedB = new Derived();
    delete derivedB;
    cout << "--------------------" << endl << endl;


    VirtBase* virtbase = new VirtBase();
    delete virtbase;
    cout << "--------------------" << endl;

    VirtBase* virtderivedA = new VirtDerived();
    delete virtderivedA;
    cout << "--------------------" << endl;

    VirtDerived* dvirterivedB = new VirtDerived();
    delete dvirterivedB;
    cout << "--------------------" << endl;
}



Base::Base()
{
    cout << "Base constructor" << endl;
}


Base::~Base()
{
    cout << "Base destructor" << endl;
}


Derived::Derived()
{
    cout << "   Derived constructor" << endl;
}


Derived::~Derived()
{
    cout << "   Derived destructor" << endl;
}


VirtBase::VirtBase()
{
    cout << "VirtBase constructor" << endl;
}


VirtBase::~VirtBase()
{
    cout << "VirtBase destructor" << endl;
}


VirtDerived::VirtDerived()
{
    cout << "   VirtDerived constructor" << endl;
}


VirtDerived::~VirtDerived()
{
    cout << "   VirtDerived destructor" << endl;
}