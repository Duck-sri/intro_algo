#include <bits/stdc++.h>
#include "include/BST.h"
using namespace std;

int main() {
    srand(time(NULL));
    vector<int> values;
    BST<int> tree;
    int N = rand()%25+5;
    for(int i=0;i < N; i++) {
        int tmp = (rand() % 100) -1;
        values.push_back(tmp);
        cout << tmp << ' ';
        tree.insert(tmp);
    } cout << '\n';

    cout << '\n' << "The Tree height : " << tree.depthPre() << ' ' << tree.depthPost() <<  '\n'  << tree;
    tree.invertTree();
    cout << '\n' << "The Tree height after invert : " << tree.depthPre() << ' ' << tree.depthPost() <<  '\n'  << tree;
    tree.invertTree();
    cout << "Sorted output : \n";
    tree.sortedOut();
    return 0;
}
