#include<assert.h>
#include<iostream>

class ClassA 
{
public:
    int sum(int a=10, int b=15);
};


int main()
{
    ClassA classA;

    assert(classA.sum() == classA.sum(10));
    assert(classA.sum() == classA.sum(10, 15));
}


int ClassA::sum(int a, int b)
{
    std::cout << a+b << std::endl;
    return a+b;
}