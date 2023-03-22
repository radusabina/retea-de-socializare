//
// Created by Sabina on 5/14/2022.
//

#pragma once
#include "BST.h"
#include <vector>

template<class T>
class Set {
private:
    BST<T> elems;
public:
    Set() = default;

    void adauga(T elem) {
            elems.add(elem);
        }

    void remove(T elem){
        if (elems.search(elem)) {
            elems.remove(elem);
        }
    }

    void update(T elem, T new_elem) {
        elems(elem, new_elem);
    }

    vector<T> get_all() {
        return elems.get_all();
    }
};