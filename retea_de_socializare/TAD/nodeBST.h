//
// Created by Sabina on 5/13/2022.
//
#pragma once

template <class T>
class BST;

template <class T>
class NodeBST {
private:
    T info;
    NodeBST<T>* left;
    NodeBST<T>* right;
public:
    NodeBST() = default;

    NodeBST(T info) {
        this->info = info;
        left = nullptr;
        right = nullptr;
    }
    NodeBST(T info, NodeBST<T>* left, NodeBST<T>* right) {
        this->info = info;
        this->left = left;
        this->right = right;
    }

    ~NodeBST() = default;

    friend class BST<T>;
};