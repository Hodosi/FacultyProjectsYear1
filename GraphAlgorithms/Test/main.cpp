#include <iostream>
#include <set>

using namespace std;

// Structure definition
struct Test {
    int id;

    // This function is used by set to order
    // elements of Test.
    bool operator<(const Test& t) const
    {
        return (this->id < t.id);
    }
};

// Driver method
int main()
{
    // put values in each
    // structure define below.
    Test* t1 = new Test{ 110 };
    Test* t2 = new Test{ 102 };
    Test* t3 = new Test { 101 };
    Test* t4 = new Test{ 115 };

    // define a set having
    // structure as its elements.
    set<struct Test*> s;

    // insert structure in set
    s.insert(t1);
    s.insert(t2);
    s.insert(t3);
    s.insert(t4);

    // define an iterator to iterate the whole set.
    set<struct Test*>::iterator it;

    for (it = s.begin(); it != s.end(); it++)
    {
        // print in ascending order as required.
        cout << (*it)->id << endl;
    }

    return 0;
}