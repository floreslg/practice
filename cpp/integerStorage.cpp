#include<assert.h>
#include<iostream>

class IntegerStorage
{
public:
    int intSize();
    int unsignedIntSize();
    int shortIntSize();
    int longIntSize();
    int longLongIntSize();
};


int main()
{
    IntegerStorage intSt;

    assert(intSt.intSize() == 4);
    assert(intSt.unsignedIntSize() == 4);
    assert(intSt.shortIntSize() == 2);
    assert(intSt.longIntSize() == 8);
    assert(intSt.longLongIntSize() == 8);
}


int IntegerStorage::intSize()
{
    unsigned int signedInt;
    return sizeof(signedInt);
}

int IntegerStorage::unsignedIntSize()
{
    unsigned int unsignedInt;
    return sizeof(unsignedInt);
}

int IntegerStorage::shortIntSize()
{
    short int shortInt;
    return sizeof(shortInt);
}

int IntegerStorage::longIntSize()
{
    long int longInt;
    return sizeof(longInt);
}

int IntegerStorage::longLongIntSize()
{
    long long int longLongInt;
    return sizeof(longLongInt);
}