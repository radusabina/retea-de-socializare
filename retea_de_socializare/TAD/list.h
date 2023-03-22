//
// Created by Sabina on 4/30/2022.
//
#pragma once

template <class T>
class List {
private:
    int nr_elems;
    int size;
    T* array;
    void resize() {
        if (nr_elems == size) {
            T *new_array = new T[size * 2];
            for (int i = 0; i < size; i++) new_array[i] = array[i];
            size *= 2;
            delete[] array;
            array = new_array;
        }
    }
public:
    List() {
        nr_elems = 0;
        size = 10;
        array = new T[size];
    }

    void add(T elem) {
        resize();
        array[nr_elems] = elem;
        nr_elems++;
    }

    int search(T elem) {
        int i = 0;
        while(i < nr_elems) {
            if(array[i] == elem) return i;
            else i++;
        }
        return -1;

    }

    int remove(T elem) {
        int poz = search(elem);
        if(array[poz] == elem){
            for(int i = poz; i < nr_elems-1; i++) array[i] = array[i+1];
            nr_elems--;
            return 1;
        }
        return 0;
    }

    int update(T elem, T new_elem) {
        int poz = search(elem);
        if (array[poz] == elem) {
            array[poz] = new_elem;
            return  1;
        }
        return  0;
    }

    int get_nr_elems() {
        return nr_elems;
    }

    T operator[](int index) {
        return array[index];
    }

    ~List() {
        nr_elems = 0;
        size = 10;
    }
};
