#pragma once
#include "Bector.hpp"


template <typename V>
void Bector<V>::resize(){
    V *newArr = new V[capacity*2];

    for(int i = 0; i<capacity; i++){
        newArr[i] = array[i];
    }

    delete[] array;
    capacity = capacity*2;
    array = newArr;
}


template <typename V>
Bector<V>::Bector()
: size(0), capacity(1), array(new V[capacity])
{
    // size = 0;
    // capacity = 1;
    // array = new V[capacity];
}


// template <typename V, typename... Rest>
// Bector<V>::Bector(V value, Rest... args){
//     size = 0;
//     capacity = 1;
//     array = new V[capacity];

//     push_args(*this, value, args...);

//     // while(value != NULL){
//     //     push_back(value);
//     //     value = va_arg(args, V);
//     // }

//     // va_end(args);
// }


template <typename V>
Bector<V>::Bector(V arr[], int n){
    size = n;
    capacity = 2*n;
    array = new V[capacity];

    for(int i = 0; i < n; i++)
        array[i] = arr[i];
}




template <typename V>
Bector<V>::~Bector(){
    // delete[] array;
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
void Bector<V>::set(int index, V value){
    if(index >= size) throw std::runtime_error("Err: Segfault!");

    array[index] = value;
}


template <typename V>
V Bector<V>::get(int index) const{
    if(index >= size) throw std::runtime_error("Err: Segfault!");

    return array[index];
}


template <typename V>
void Bector<V>::push_back(V value){
    if(size == capacity-1) resize();
    array[size++] = value;
}


template <typename V>
void Bector<V>::pop_back() const{
    if(size == 0) return;
    size--;
}


template <typename V>
V Bector<V>::head() const{
    return array[0];
}


template <typename V>
Bector<V> Bector<V>::tail() const{
    return Bector<V>(array+1, size-1);
}


template <typename V>
V Bector<V>::back() const{
    return array[size-1];
}


template <typename V>
V *Bector<V>::begin(){
    return array;
}


template <typename V>
V *Bector<V>::end(){
    return array + size;
}


template <typename V>
V &Bector<V>::at(int index){
    if(index >= size){
        throw "Err: Segfault!";
    }

    return array[index];
}


template <typename V>
V &Bector<V>::operator[](int index){
    if(index >= size){
        throw "Err: Segfault!";
    }

    return array[index];
}
