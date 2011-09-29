#include <iostream>


using namespace std;


class Test {

private:
    string name;

public:
    Test (const string& s) : name(s) {}

    //has visibility for the name parameter from the other class even been
    //private
    Test (const Test& rhs) {name = "copy ctor called: " + rhs.name;} 

    Test& operator= (const Test& rhs) {name = "(" + name + ")" + "copy operator called: " + rhs.name;}

    void doit () {cout << "did it from " << name << endl;}


};


int main() {


    Test t1("t1");
    t1.doit ();

    Test t2("t2");
    t2.doit ();

    Test t3(t2); //passing t2 object as argument - not string - should call copy ctor
    t3.doit();

    Test t4("t4");
    t4.doit();

    t4 = t1; // copy operator= copied here
    t4.doit();

    // copy ctor called instead of operator=. This happens because here I am
    // creating a new object and not copying an object to another. This way a
    // ctor copy must be called. See page page 6 third line of Effective C++
    // third edition
    Test t5 = t2; 
    t5.doit(); 
    

    return 0;
}
