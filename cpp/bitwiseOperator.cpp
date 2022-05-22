#include<iostream>
#include<assert.h>
#include<bitset>

using namespace std;


class strBitSet
{
public:
    static string AND(const string& strBin1, const string& strBin2);
    static string OR(const string& strBin1, const string& strBin2);
    static string XOR(const string& strBin1, const string& strBin2);
    static string NOT(const string& strBin1);
    static string LEFTSHIFT(const string& strBin1, const int& n);
    static string RIGHTSHIFT(const string& strBin1, const int& n);
};


int main()
{
    assert(strBitSet::AND("00011100",
                          "11110011") == "00010000");

    assert(strBitSet::OR("00011100",
                         "11110010") == "11111110");

    assert(strBitSet::XOR("00011100",
                          "11110011") == "11101111");

    assert(strBitSet::NOT("11110011") == "00001100"); 

    assert(strBitSet::LEFTSHIFT("11110011", 1) == "11100110");

    assert(strBitSet::RIGHTSHIFT("11110011", 2) == "00111100");  
}


string strBitSet::AND(const string& strBin1, const string& strBin2)
{
    bitset<8> bin1(strBin1);
    bitset<8> bin2(strBin2);
    return (bin1 & bin2).to_string();
}


string strBitSet::OR(const string& strBin1, const string& strBin2)
{
    bitset<8> bin1(strBin1);
    bitset<8> bin2(strBin2);
    return (bin1 | bin2).to_string();
}


string strBitSet::XOR(const string& strBin1, const string& strBin2)
{
    bitset<8> bin1(strBin1);
    bitset<8> bin2(strBin2);
    return (bin1 ^ bin2).to_string();
}


string strBitSet::NOT(const string& strBin1)
{
    bitset<8> bin1(strBin1);
    return (~bin1).to_string();
}


string strBitSet::LEFTSHIFT(const string& strBin1, const int& n)
{
    bitset<8> bin1(strBin1);
    return (bin1<<n).to_string();
}


string strBitSet::RIGHTSHIFT(const string& strBin1, const int& n)
{
    bitset<8> bin1(strBin1);
    return (bin1>>n).to_string();
}