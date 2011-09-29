#include <iostream>
#include <vector>


using namespace std;


class produto {

public:
    virtual float getPrice () = 0; 
};

class bolacha : public produto {

public:
    float getPrice () {return 3.5;}
};

class refrigerante : public produto {

public:
    float getPrice () {return 5.0;}
};

float calculaTotal (vector<produto *> p) {

    float total = 0.0;

    for (int i=0; i<p.size(); i++) {
        cout << "item: " << p[i]->getPrice() << endl;
        total += p[i]->getPrice();
    }
    return total;
}

int
main() {

    vector<produto *> p;

    bolacha b = bolacha();
    refrigerante r = refrigerante();


    p.push_back(&b);
    p.push_back(&b);
    p.push_back(&r);
    p.push_back(&b);

    cout << "TOTAL ---> " << calculaTotal(p) << endl;

    return 0;
}
