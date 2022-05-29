#include<iostream>
#include<vector>
#include<tuple>
#include <iterator>
using namespace std;



enum class Relationship {Parent, Child};
struct Person {string _name;};


class RelationshipBrowser
{
public:
    virtual vector<Person> findAllChildrenOf(const string& name) =0;
};


class Relationships : public RelationshipBrowser
{
public:
    vector<tuple<Person, Relationship, Person>> _relations;
    void addParentChild(const Person& parent, const Person& child);
    vector<Person> findAllChildrenOf(const string& name) override;
};


class Research
{
public:
    Research(RelationshipBrowser& browser);
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
}


void Relationships::addParentChild(const Person& parent, const Person& child)
{
    _relations.push_back({parent, Relationship::Parent, child});
    _relations.push_back({child, Relationship::Child, parent});
}

vector<Person> Relationships::findAllChildrenOf(const string& name)
{
    vector<Person> result;
    for (auto& [person1, relation, person2] : _relations)
    {
        if (person1._name == name && relation == Relationship::Parent)
        {
            result.push_back(person2);
        }
    }
    
    return result;
};


Research::Research(RelationshipBrowser& browser)
{
    for (auto& child : browser.findAllChildrenOf("John"))
    {
        cout << "John has a child called " << child._name << endl;
    }
}
