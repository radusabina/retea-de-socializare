//
// Created by Sabina on 5/13/2022.
//

#pragma once
#include "nodeBST.h"
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class BST {
private:
    NodeBST<T> *root;

    void add_elem(NodeBST<T> *node, T elem) {
        if (node->info > elem) { // add on the left
            if (node->left != nullptr) {
                add_elem(node->left, elem);
            } else {
                node->left = new NodeBST<T>(elem, nullptr, nullptr);
            }
        } else {  //adaugam on the right
            if (node->right != nullptr) {
                add_elem(node->right, elem);
            } else {
                node->right = new NodeBST<T>(elem, nullptr, nullptr);
            }
        }
    }

    NodeBST<T>* remove_elem(NodeBST<T>* node, T elem) {
        if (node == nullptr) return node;
        if (elem < node->info) node->left = remove_elem(node->left, elem);
        else if (elem > node->info) node->right = remove_elem(node->right, elem);
        else {
            if (node->left == nullptr && node->right == nullptr) {
                if (this->root->info == node->info) this->root = nullptr;
                return nullptr;
            }
            else if (node->left == nullptr) {
                if (this->root == node) this->root = node->right;
                node = node->right;
                return node;
            }
            else if (node->right == nullptr) {
                if (this->root == node) this->root = node->left;
                node = node->left;
                return node;
            }
            NodeBST<T>* aux = find_minim(node->right);
            node->info = aux->info;
            node->right = remove_elem(node->right, aux->info);
            if (this->root == nullptr) this->root = node;
        }
        return node;
    }

    NodeBST<T>* find_minim(NodeBST<T>* node) {
        while (node->left != nullptr) this->root = node;
        return node;
    }

    void update_elem(NodeBST<T>* node, T elem, T new_elem) {
        this->remove_elem(node, elem);
        this->add_elem(node, new_elem);
    }

    void afisare_in(NodeBST<T>* node) {
        if (node != nullptr) {
            afisare_in(node->left);
            cout << node->info << " ";
            afisare_in(node->right);
        }
    }

    bool search_elem(NodeBST<T> *node, T elem) {
        if (node->info == elem)
            return true;
        else if (elem < node->info) {
            if (node->left == nullptr)
                return false;
            return search_elem(node->left, elem);
        } else {
            if (node->right == nullptr)
                return false;
            return search_elem(node->right, elem);
        }
    }

    vector<T> get_all_elems(NodeBST<T>* node, vector<T>& elems) {
        if (node != nullptr) {
            get_all_elems(node->left, elems);
            elems.push_back(node->info);
            get_all_elems(node->right, elems);
        }
        return elems;
    }

public:
    BST() {
        this->root = nullptr;
    }

    void add(T elem) {
        if (this->root == nullptr) this->root = new NodeBST<T>(elem, nullptr, nullptr);
        else add_elem(this->root, elem);
    }

    bool search(T elem) {
        return search_elem(this->root, elem);
    }

    void remove(T elem) {
        remove_elem(this->root, elem);
    }

    void update(T elem, T new_elem) {
        update_elem(this->root, elem, new_elem);
    }

    void afisare() {
        afisare_in(this->root);
        cout << endl;
    }

    vector<T> get_all() {
        vector<T> elems;
        get_all_elems(this->root, elems);
        return elems;
    }

    ~BST() {
        if (root) delete root;
    }
};

