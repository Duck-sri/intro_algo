#include <bits/stdc++.h>
#include "include/BST.h"
using namespace std;

int main() {
    srand(time(NULL));
    vector<int> values;
    BST<int> tree;
    for(int i=0;i < 20 ; i++) {
        int tmp = (rand() % 100) -1;
        values.push_back(tmp);
        cout << tmp << ' ';
        tree.insert(tmp);
    } cout << '\n';

    cout << '\n' << "The Tree \n"  << tree;
    return 0;

}
