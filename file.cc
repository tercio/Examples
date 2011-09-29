#include <iostream>
#include <fstream>


using namespace std;

int
main () {

    ifstream in ("use_vector.cc");

    if (!in.is_open()) {
        cerr << " error opening file " << endl;
        return 1;
    }

    char buffer[255];
    int i=0;
    while (in.getline(buffer,254)) {
    
        cout << ++i << ": "<<buffer<<endl;
    }



    return 0;
}
