#include <iostream>
#include <iomanip>

using namespace std;

int
main () {


    //
    // Exemplos no livro C++ Primer a partir da pagina 1114
    // 

    cout << "teste" << setw(20) << "teste2"<<endl;

    cout << setw(16) << setfill ('*') << "teste" << endl;

    double v = 12.63453455;
    cout.precision(8);
    cout << "v: " << v<<endl;

    v = 10.0;
    cout << v << endl;
    cout << showpoint << v << endl;

    int iv = 28;
    cout << hex << iv << endl;
    cout << dec << iv << endl;
    cout << oct << iv <<endl;
    cout << dec << iv << endl<<endl;

    cout << showbase;
    cout << hex << iv << endl;
    cout << dec << iv << endl;
    cout << oct << iv <<endl;
    cout << dec << iv << endl <<endl;
    cout << noshowbase;
    
    bool b = true;

    cout << b << endl;
    cout << boolalpha << b << noboolalpha<<endl;


    return 0;
}
