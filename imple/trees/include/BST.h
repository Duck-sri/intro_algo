#pragma once

#include <iostream>
#include <vector>
#include <queue>

#include "./Node.h"

template <typename T>
class BST {
    Node<T>* root;

    // prototypes
    Node<T>* find(T key,Node<T>* root);
public:
    BST() : root(nullptr) {}
    BST(Node<T>* root) : root(root) {}
    void insert(T val);
    Node<T>* find(T key);
    std::vector<std::vector<T>> print();
    std::ostream& operator << (std::ostream& os);
};

template <typename T>
void BST<T>::insert(T val) {
    Node<T>* tmpNode = new Node<T>(val);
    if (this->root == nullptr) { 
        tmpNode->lvl = 1;
        this->root = tmpNode;
    }
    else {
        Node<T>* currNode = this->root;
        int count = 1;
        while(true) {
            count++;
            if( val <= currNode->val) {
                if (currNode->left == nullptr) {
                    tmpNode->lvl = count;
                    currNode->left = tmpNode;
                    return;
                } else currNode = currNode->left;
            }
            else {
                if (currNode->right == nullptr) {
                    tmpNode->lvl = count;
                    currNode->right = tmpNode;
                    return;
                } else currNode = currNode->right;
            }
        }
    }
}

template <typename T>
Node<T>* BST<T>::find(T key) {
    Node<T>* root = this->root;
    // break condition
    if (root->val == key)  return root;

    if ((root->left != nullptr) and (key <= root->left->val)) return find(key,root->left);
    if ((root->right !=nullptr) and (key > root->right->val)) return find(key,root->right);

    // if a leaf and doens't have the key
    return nullptr;
}

template <typename T>
Node<T>* BST<T>::find(T key,Node<T>* root) {
    if (root == nullptr) root = this->root;
    // break condition
    if (root->val == key)  return root;

    if ((root->left != nullptr) and (key <= root->left->val)) return find(key,root->left);
    if ((root->right !=nullptr) and (key > root->right->val)) return find(key,root->right);

    // if a leaf and doens't have the key
    return nullptr;
}

template <typename T>
std::vector<std::vector<T>> BST<T>::print() {
    std::vector<std::vector<T>> res;
    if (this->root == nullptr) return res;
    std::queue<Node<T>*> q;
    q.push(this->root);
    while(!q.empty()) {
        std::vector<T> tmpRes;
        int lvlSize = q.size();
        while(lvlSize--) {
            Node<T>* tmpRoot = q.front();q.pop();
            tmpRes.push_back(tmpRoot->val);
            if (tmpRoot->left != nullptr) q.push(tmpRoot->left);
            if (tmpRoot->right != nullptr) q.push(tmpRoot->right);
        }
        res.push_back(tmpRes);
    }

    return res;
}

template <typename T>
std::ostream& operator << (std::ostream& os,BST<T>& tree) {
    std::vector<std::vector<T>> res = tree.print();
    int lvl = 1;
    for(std::vector<int> x : res) {
        os << "Level : " << lvl << " -> ";
        for (T y : x ) {
            os << y << ' ';
        }
        os << '\n';
        lvl++;
    }
    return os;
}
