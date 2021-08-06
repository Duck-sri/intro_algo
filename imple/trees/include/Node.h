#pragma once

template <typename T>
struct Node {
    T val;
    Node *left,*right;
    int subTreeSize=0;

    Node() : val(0), left(nullptr),right(nullptr) {}
    Node(T val) : val(val),left(nullptr),right(nullptr) {}
    Node(T val,Node* left, Node* right) : val(val),left(left),right(right) {}
    
    bool isLeaf() { return ( (this->left == nullptr) and (this->right == nullptr) ); }
};
