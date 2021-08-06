#pragma once

template <typename T>
struct Node {
    T val;
    int lvl;
    Node *left,*right;

    Node() : val(0), left(nullptr),right(nullptr) {}
    Node(T val) : val(val),left(nullptr),right(nullptr) {}
    Node(T val,Node* left, Node* right) : val(val),left(left),right(right) {}
};
