#include<assert.h>


struct structureShallow
{
    int data1;
    int* data2;
};


struct structureDeep
{
    int data1;
    int* data2;

    structureDeep();
    structureDeep(structureDeep& str);
};


int main()
{
    int a = 10;
    int b = 100;
    int* c = &b;

    // shallow copy
    structureShallow str1;
    str1.data1 = a;
    str1.data2 = c;
    structureShallow str2(str1);

    assert(&str1 != &str2);
    assert(&str1.data1 != &str2.data1);
    assert(str1.data2 == str2.data2); // shared ptr (not a copy).

    // deep copy
    structureDeep strA;
    strA.data1 = a;
    strA.data2 = c;
    structureDeep strB(strA);

    assert(&strA != &strB);
    assert(&strA.data1 != &strB.data1);
    assert(strA.data2 != strB.data2); // copy constructor use different adress.
}


structureDeep::structureDeep()
{
    data2 = new int;
}


structureDeep::structureDeep(structureDeep& str)
{
    data1 = str.data1;
    data2 = new int;
    *data2 = *(str.data2);
}
