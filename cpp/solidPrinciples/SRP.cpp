#include<assert.h>
#include<iostream>
#include <fstream>
#include<vector>
using namespace std;



class Journal
{
    string _title;
    vector<string> _entries;

public:
    explicit Journal(const string& title);

    void addEntries(const string& entry);
    vector<string> getEntries() const;
};


class SavingManager
{
public:
    static void save(const Journal& journal, const string& filename);
};

int main()
{
    Journal journal("Dear c++,");
    journal.addEntries("I don't violated SRP");
    journal.addEntries("Journal has only one reason to change");

    SavingManager::save(journal, "journal.out");
}


Journal::Journal(const string& title) : _title(title) {};

void Journal::addEntries(const string& entry)
{_entries.push_back(entry);}

vector<string> Journal::getEntries() const
{return _entries;}


void SavingManager::save(const Journal& journal, const string& filename)
{
    ofstream ofs(filename); 
    for (auto &s : journal.getEntries()) {ofs << s << endl;}
}