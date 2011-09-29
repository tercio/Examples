#include <vector>
#include <iostream>

using namespace std;

template<class T>
class vector_inserter {

public:
    vector_inserter (vector <T>& _v) : v(_v) {commited = false;}

    void add (T t) {v.push_back(t);}

    void commit () {commited = true;}

    ~vector_inserter () {
        if (!commited) {
            v.pop_back();
        }
    }
private:
    bool commited;
    vector<T>& v;
};

int
main() {

    vector<int> v;
    {
        vector_inserter<int> vi (v);
        vi.add(1);
        vi.commit();
    }

    {
        vector_inserter<int> vi (v);
        vi.add(2);
        //vi.commit();
    }
    
    {
        vector_inserter<int> vi (v);
        vi.add(3);
        vi.commit();
    }

    for (int i=0; i< v.size(); i ++) 
        cout << v[i] <<endl;

    return 0;
}

