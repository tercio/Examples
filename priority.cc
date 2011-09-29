#include <iostream>
#include <queue>

using namespace std;

template <class T>
class myComparison {

public:

    bool operator() (const T& lhs, const T&rhs) {
        return lhs > rhs;
    }

};

int main(){


    priority_queue <int> pq;

    pq.push (1);
    pq.push (3);
    pq.push (2);
    pq.push (5);
    pq.push (4);
    pq.push (6);

    cout << "added to the pq: 1 3 2 5 4 6" << endl;
    
    cout << "NOTE: by default, priority queue return the greater entry first, so the result below..." << endl;
    while (!pq.empty()) {

        int i = pq.top();
        pq.pop();
        cout << i << endl;

    }

    cout << "let's change the algorithm of comparison to return the lowest before...";

    priority_queue<int,vector<int>,myComparison<int> > pq2;
    pq2.push (1);
    pq2.push (3);
    pq2.push (2);
    pq2.push (5);
    pq2.push (4);
    pq2.push (6);

    cout << "added to the pq: 1 3 2 5 4 6" << endl;

    while (!pq2.empty()) {

        int i = pq2.top();
        pq2.pop();
        cout << i << endl;

    }

    return 0;
}
