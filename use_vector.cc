#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class ordena {

public:

    int operator() (const string &a, const string &b) {
        return a < b;
    }

};

int
main () {

    vector<string> v;

    v.push_back("Windows");
    v.push_back("Linux");
    v.push_back("FreeBSD");
    v.push_back("MacOS X");

    for (int i=0; i<v.size(); i++)
        cout << v[i] <<endl;

    sort (v.begin(), v.end(), ordena());

    cout << endl << "-- Versao ordenada --" << endl;
    for (int i=0; i<v.size(); i++)
        cout << v[i] <<endl;

    return 0;
}
