#pragma once

template <typename T>
struct Node {
    T val;
    Node *left,*right;
    int height; // max(height(left)+height(y))+1
    int depth; // leaft has 0, and nullptr has -1 so (max(-1,-1)+1 = 0)
    int subTreeSize=0;

    Node() : val(0), left(nullptr),right(nullptr) {}
    Node(T val) : val(val),left(nullptr),right(nullptr) {}
    Node(T val,Node* left, Node* right) : val(val),left(left),right(right) {}
    
    bool isLeaf() { return ( (this->left == nullptr) and (this->right == nullptr) ); }
};

template <typename T>
int heightNode(Node<T>* root) {
    if (root->isLeaf()) root->height=1; 
    else root->height =  (root->left->heightNode()>root->right->heightNode()?root->left->height:root->right->height) + 1;
    return root->height;
}

template <typename T>
int depthNode(Node<T>* root) {
    if (root == nullptr) return -1;
    if (root->isLeaf()) root->depth=0; 
    else root->depth =  (root->left->depthNode()>root->right->depthNode()?root->left->depth:root->right->depth) + 1;
    return root->depth;
}
