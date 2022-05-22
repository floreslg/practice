
#include<assert.h>


class TernaryOperator
{
    public:
    bool testIsGreaterThan3(const int&);
};


int main()
{
    TernaryOperator terOp;

    int testValue = 4;
    bool expected = true;
    bool returned = terOp.testIsGreaterThan3(testValue);

    assert(expected==returned);
}


bool TernaryOperator::testIsGreaterThan3(const int& testValue)
{
    return testValue > 3 ? true : false;
};