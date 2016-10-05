/*


   0 ------------- 2 -- 3 ---  4
    \               \         /
     \               \       /
      \1 -- 5 -- 6 -- 7 ----/     


 O Breadth First faria algo parecido como (mostrando em camadas:
e le os nodes por camadas, por exemplo:

0
1 2
5 3 7
6
4


                               0
                             /   \
                            1     2
                           /     / \
                          5     3   7 --
                         /       \  /  |
                        6 ---------    |
                                   \ ---
                                      4

*/


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main () {


    vector< vector <int> > v;
    vector<int> temp;

    // node 0
    temp.push_back(1);
    temp.push_back(2);
    v.push_back(temp);
    temp.clear();

    // node 1
    temp.push_back(5);
    v.push_back(temp);
    temp.clear();
    
    // node 2
    temp.push_back(3);
    temp.push_back(7);
    v.push_back(temp);
    temp.clear();
    
    // node 3
    temp.push_back(4);
    v.push_back(temp);
    temp.clear();

    // node 4 n~ao esta conectado a ninguem, porem ele existe!
    //temp.push_back(3);
    //temp.push_back(7);
    v.push_back(temp);
    temp.clear();

    // node 5
    temp.push_back(6);
    v.push_back(temp);
    temp.clear();

    // node 6
    temp.push_back(7);
    v.push_back(temp);
    temp.clear();

    // node 7
    temp.push_back(4);
    v.push_back(temp);
    temp.clear();

    vector<int>::iterator it;

    // Coloque aqui o node que deseja iniciar a pesquisa
    int start_vertex = 2;

    // coloque aqui o node que deseja saber se esta conectado ao inicial
    int nodeToFind = 4;

    int N = 8; // number of vertices

    vector <int> V(N,false);
    queue<int> Q;
    Q.push (start_vertex);
    V[start_vertex] = true;

    while (!Q.empty()) {

        int i = Q.front();
        Q.pop();
        cout << " will run the list for i(node) = " << i << endl;
        for (it=v[i].begin(); it < v[i].end(); it++) {

            // so revisita os nodes que ainda nao viu, sendo assim
            // nao encontra um node por dois caminhos diferentes, como o node 4 por exemplo
            if (!V[*it]) {
                V[*it] = true; 
                Q.push (*it);
                cout << " pushing to the queue : " << *it<<endl;
                if (*it == nodeToFind)
                    cout << "----> found! " << nodeToFind <<endl;
            }

        }


    }


    it = find (V.begin(),V.end(),0);
    cout << *it<<endl;

    
    

    return 0;

}
