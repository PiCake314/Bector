#pragma once

#include <functional>

template <typename V>
class Bector{
    private:
        int size;
        int capacity;
        V *array;

        void resize();

    public:

        Bector();

        ~Bector();

        int getSize();

        int getCapacity();

        void set(int index, V value);

        V get(int index);

        V &at(int index);

        V &operator[](int index);

        void push_back(V value);

        void pop_back();

        V head(){
            return array[0];
        }

        Bector<V> tail(){
            Bector<V> b;
            for(int i = 1; i < size; i++){
                b.push_back(array[i]);
            }
            return b;
        }

        
        // // semi works
        // template <typename T>
        // std::function<T(std::function<T(T, V)>)> fold(T init){
        //     return [this, &init](std::function<T(T, V)> func){
        //         for(int i = 0; i < size; i++){
        //             init = func(init, array[i]);
        //         }
        //         return init;
        //     };
        // }

        
        template <typename T>
        std::function<T(std::function<T(T, V)>)> fold(const T &value){
            return [this, &value](std::function<T(T, V)> func){
                if(size <= 0) return value;

                return tail().fold(func(value, head()))(func);
            };
        }

        
        // template <typename T>
        // T(*)(T(*)(T, V)) fold(const T &value){
        //     return [this, &value](std::function<T(T, V)> func){
        //         if(size <= 0) return value;

        //         return tail().fold(func(value, head()))(func);
        //     };
        // }

};

#include "Bector.tpp"