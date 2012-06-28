/*****************************************************************************
 *
 *  http://www.drdobbs.com/cpp/c11-uniqueptr/240002708
 *
 *
 *****************************************************************************/

#include <iostream>
#include <vector>
#include <memory>


using namespace std;

class Foo {
public:
    Foo (int v) : value (v) {}
    
    void printV () {cout << value << endl;}

    ~Foo () {cout << "destructor called..." << endl;}

private:
    int value;

};

void func (unique_ptr<Foo>& f){

    cout << "inside func()..." << endl;
    f->printV();

}

// espera um pointer
void func2 (Foo* f) {


    cout << "inside func2..." << endl;
    f->printV();
}

int main () {

    unique_ptr<Foo> i (new Foo (3));

    i->printV();

    func(i);
    func2 (i.get());

    vector< unique_ptr<Foo> > v;
    //v.push_back(i); // erro de compilacao pois e necessario usar o move abaixo

    v.push_back(move(i)); 
    v[0]->printV();

    // se chamar func aqui passando i, teremos um seg fault, ja que apos o move acima
    // i e igual a NULL
    //func(i);

    return 0;
}
