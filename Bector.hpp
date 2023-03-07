#pragma once

// #include <functional>

template <typename V>
class Bector{
    private:
        int size;
        int capacity;
        V *array;

        void resize();

    public:

        Bector();
        Bector(V, ...);
        Bector(V[], int);

        ~Bector();

        int getSize();

        int getCapacity();

        void set(int index, V value);

        V get(int index);

        V &at(int index);

        void push_back(V value);

        void pop_back();


        V head();

        Bector<V> tail();

        V back();

        V *begin();

        V *end();

        
        template <typename T>
        std::function<T(std::function<T(T, V)>)> fold(const T &value){
            return [this, &value](std::function<T(T, V)> func){
                if(size <= 0) return value;

                return tail().fold(func(value, head()))(func);
            };
        }


        V &operator[](int index);
};

#include "Bector.tpp"