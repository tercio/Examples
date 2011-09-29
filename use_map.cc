#include <map>
#include <string>
#include <iostream>

using namespace std;

int
main() {


    map<string,string> m;

    m["Tercio"] = "1971";
    m["Marcia"] = "1974";
    m["Monique"] = "1992";
    m["Junior"] = "1995";

    map<string,string>::iterator it; 

    for (it = m.begin(); it != m.end(); it++) {
        cout << it->first << " === " << it->second << endl;
    }

    return 0;
}
