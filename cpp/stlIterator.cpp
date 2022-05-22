#include<assert.h>
#include<vector>
#include<iostream>

using namespace std;


class Math
{
public:
    vector<float> hadamardProduct(vector<float> v1, vector<float> v2);

    float getNthBeforeIth(vector<float> v, int i, int n);
};


int main()
{
    Math math;
    
    vector<float> v1 = {1, 2, 3, 4};
    vector<float> v2 = {0, 2, 2, 0};
    vector<float> v1v2 = {0, 4, 6, 0};
    
    assert(v1v2 == math.hadamardProduct(v1, v2));
    assert(math.getNthBeforeIth(v1, 2, 1) == 2);

}


vector<float> Math::hadamardProduct(vector<float> v1, vector<float> v2)
{
    vector<float>::iterator i;
    vector<float>::iterator j;
    vector<float> v1v2;

    for (i=v1.begin(), j=v2.begin(); i<v1.end(), j<v2.end(); i++, j++)
    {
        v1v2.push_back(*i * *j);
    }

    return v1v2;
}


float Math::getNthBeforeIth(vector<float> v, int i, int n)
{
    vector<float>::iterator iter = v.begin();
    return *prev(next(iter, i), n);
}