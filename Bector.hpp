#pragma once

int x = -32;


template <typename V>
class Bector{
    private:
        int size;
        int capacity;
        V *array;

        void resize();

    public:

        Bector();

        int getSize();

        int getCapacity();

        void set(int index, int value);

        int get(int index);

        int &at(int index);

        void push_back(int value);

        void pop_back();
};

#include "Bector.tpp"