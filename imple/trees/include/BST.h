#pragma once

#include <iostream>
#include <vector>
#include <queue>
#define rep(i,N) for(int i=0,i<N;i++)
#define repRev(i,N) for(int i=N,i>0;i--)

#include "./Node.h"

template <typename T>
class BST {
    Node<T>* root;
    int height=0;

    // prototypes
    Node<T>* find(T key,Node<T>* root);
    void depthPre(Node<T>* root,int height);
    int depthPost(Node<T>* root);
    void invertTree(Node<T>* root);
    int addSubTreeSizes(Node<T>* root);
    void sortedOut(Node<T>* root);
public:
    BST() : root(nullptr) {}
    BST(Node<T>* root) : root(root) {}
    void insert(T val);
    Node<T>* find(T key);
    std::vector<std::vector<T>> print();
    std::ostream& operator << (std::ostream& os);
    int depthPre();
    int depthPost();
    int addSubTreeSizes();
    void invertTree();
    void sortedOut();
};

template <typename T>
void BST<T>::insert(T val) {
    Node<T>* tmpNode = new Node<T>(val);
    if (this->root == nullptr) { 
        this->root = tmpNode;
    }
    else {
        Node<T>* currNode = this->root;
        while(true) {
            if( val <= currNode->val) {
                if (currNode->left == nullptr) {
                    currNode->left = tmpNode;
                    return;
                } else currNode = currNode->left;
            }
            else {
                if (currNode->right == nullptr) {
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

template <typename T>
void BST<T>::depthPre(Node<T>* root,int height) {
    if (root->isLeaf()) { 
        this->height = this->height>height ? this->height : height;
    }

    if (root->left != nullptr) depthPre(root->left,height+1);
    if (root->right != nullptr) depthPre(root->right,height+1);
}

template <typename T>
int BST<T>::depthPre() {
    if (this->root == nullptr) return 0;
    Node<T>* root = this->root;
    int height = 1;

    if (root->left != nullptr) depthPre(root->left,height+1);
    if (root->right != nullptr) depthPre(root->right,height+1);

    return this->height;
}

template <typename T>
int BST<T>::depthPost(Node<T>* root) {
    if (root == nullptr) return 0;

    int lh = depthPost(root->left);
    int rh = depthPost(root->right);
    return (lh>rh?lh:rh) + 1;
}

template <typename T>
int BST<T>::depthPost() {
    if (this->root == nullptr) return 0;
    Node<T>* root = this->root;
    int height = 1;

    int lh = depthPost(root->left);
    int rh = depthPost(root->right);
    return (lh>rh?lh:rh) + 1;
}

template <typename T>
int BST<T>::addSubTreeSizes(Node<T>* root) {
    if (root == nullptr) return 0;
    if(root->isLeaf()) return 1;
    int x =  addSubTreeSizes(root->left) + addSubTreeSizes(root->right)+1;

    //std::cout << x << '\n';
    return x;
}

template <typename T>
int BST<T>::addSubTreeSizes() {
    if (this->root == nullptr) return 0;
    Node<T>* root = this->root;
    if(root->isLeaf()) return 1;
    int x =  addSubTreeSizes(root->left) + addSubTreeSizes(root->right)+1;
    //std::cout << x << '\n';
    return x;
}

template <typename T>
void BST<T>::invertTree(Node<T>* root) {
    if (root == nullptr) return;

    if(root->isLeaf())  return;
    if(root->left != nullptr) invertTree(root->left);
    if(root->right != nullptr) invertTree(root->right);
    std::swap(root->left,root->right);
}

template <typename T>
void BST<T>::invertTree() {
    if (this->root == nullptr) return;
    Node<T>* root = this->root;

    if(root->isLeaf()) return;
    if(root->left != nullptr) invertTree(root->left);
    if(root->right != nullptr) invertTree(root->right);
    std::swap(root->left,root->right);
}

template <typename T>
void BST<T>::sortedOut(Node<T>* root) {
    if (root == nullptr) return;

    sortedOut(root->left);
    std::cout << root->val << ' ';
    sortedOut(root->right);
}

template <typename T>
void BST<T>::sortedOut() {
    Node<T>* root = this->root;
    if (root == nullptr) return;

    sortedOut(root->left);
    std::cout << root->val << ' ';
    sortedOut(root->right);
    std:: cout << '\n';
}
