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
        Bector(V, ...);
        Bector(V[], int);

        ~Bector();

        int getSize();

        int getCapacity();

        void set(int index, V value);

        V get(int index) const;

        V &at(int index);

        void push_back(V value);

        void pop_back() const;

        V head() const;

        Bector<V> tail() const;

        V back() const;

        V *begin();

        V *end();


        template <typename T>
        std::function<T(std::function<T(T, V)>)> fold(T value, bool iter = false){
            return [this, value, iter](std::function<T(T, V)> func){
                if(size <= 0) return value;
                if(!iter) return tail().fold(func(value, head()))(func);

                T acc = value;
                for(int i = 0; i < size; i++){
                    printf("%d\n", i);
                    acc = func(acc, array[i]);
                }
                return acc;
            };
        }


        V &operator[](int index);
};

#include "Bector.tpp"