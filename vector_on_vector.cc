#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int main () {


    queue <int> q;
    vector< vector <int> > v;
    vector<int> temp;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    temp.push_back(1);
    temp.push_back(2);
    v.push_back(temp);
    temp.clear();


    temp.push_back(11);
    temp.push_back(12);
    v.push_back(temp);
    temp.clear();

    temp.push_back(21);
    temp.push_back(22);
    v.push_back(temp);
    temp.clear();

    vector<int>::iterator it;

    for (it=v[2].begin(); it < v[2].end(); it++)
        cout << "-->" << *it << endl;


    return 0;

}
