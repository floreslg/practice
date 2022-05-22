#include<assert.h>
#include<iostream>


class PointerValue
{
    public:
    int getValueOf(int* ptr);
};


int main()
{
    PointerValue ptrValue;
    
    int var1 = 15;
    int* ptr = &var1;

    assert(var1 == ptrValue.getValueOf(ptr));
}


int PointerValue::getValueOf(int* ptr)
{
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
    
    return *ptr;
}