#pragma once

#include <iostream>
#include "Bector.hpp"


using namespace std;

template <typename V>
void Bector<V>::resize(){
    V *newArr = new V[capacity*2];

    for(int i=0; i<capacity; i++)
        newArr[i] = array[i];

    delete[] array;
    capacity = capacity*2;
    array = newArr;
}



template <typename V>
Bector<V>::Bector(){
    size = 0;
    capacity = 1;
    array = new V[capacity];
}



template <typename V>
int Bector<V>::getSize(){
    return size;
}



template <typename V>
int Bector<V>::getCapacity(){
    return capacity;
}



template <typename V>
void Bector<V>::set(int index, int value){
    if(index >= size){
        cerr << "Err: Segfault!" << endl;
        return;
    }

    array[index] = value;
}



template <typename V>
int Bector<V>::get(int index){
    if(index >= size){
        cerr << "Err: Segfault!" << endl;
        return -32;
    }

    return array[index];
}



template <typename V>
int& Bector<V>::at(int index){
    if(index >= size){
        cerr << "Err: Segfault!" << endl;
        return x;
    }

    return array[index];
}



template <typename V>
void Bector<V>::push_back(int value){
    if(size == capacity-1) resize();
    array[size++] = value;
}



template <typename V>
void Bector<V>::pop_back(){
    if(size == 0) return;
    array[size--] = 0;
}

