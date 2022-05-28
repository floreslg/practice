#include<assert.h>
#include<iostream>
#include <fstream>
#include<vector>
using namespace std;



class Jorunal
{
    string _title;
    vector<string> _entries;

public:
    explicit Jorunal(const string& title);

    void addEntries(const string& entry);
    vector<string> getEntries() const;
    void save(const string& filename);
};


int main()
{
    Jorunal journal("Dear c++,");
    journal.addEntries("I violated SRP, Journal has 2 reason to change");
    journal.addEntries("i. things realted to Journal, and ii. saving Journal");
    journal.save("srp.out");
}


Jorunal::Jorunal(const string& title) : _title(title) {};

void Jorunal::addEntries(const string& entry)
{_entries.push_back(entry);}

vector<string> Jorunal::getEntries() const
{return _entries;}

void Jorunal::save(const string& filename)
{
    ofstream ofs(filename); 
    for (auto &s : _entries) {ofs << s << endl;}
}

