#include<iostream>
#include<vector>
#include<tuple>
#include <iterator>
using namespace std;


enum class Relationship {Parent, Child};
struct Person {string _name;};


class Relationships
{
public:
    vector<tuple<Person, Relationship, Person>> _relations;
    void addParentChild(const Person& parent, const Person& child);
};


class Research
{
public:
    Research(const Relationships& relationships);
};


int main()
{
    Person parent{"John"};
    Person child1{"Chris"};
    Person child2{"Matt"};

    Relationships relationships;
    relationships.addParentChild(parent, child1);
    relationships.addParentChild(parent, child2);

    Research _(relationships);
};


void Relationships::addParentChild(const Person& parent, const Person& child)
{
    _relations.push_back({parent, Relationship::Parent, child});
    _relations.push_back({child, Relationship::Child, parent});
}


Research::Research(const Relationships& relationships)
{
    for (auto &[person1, relation, person2] : relationships._relations)
    {
        if (person1._name == "John" && relation == Relationship::Parent);
            cout << "John has a child called " << person2._name << endl;
    }
}