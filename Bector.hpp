#pragma once

#include <functional>

template <typename V>
class Bector{
    private:
        int size;
        int capacity;
        V *array;

        void resize();
        
        void push_args(Bector<V> &b){ return; }
        template <typename... Rest>
        void push_args(Bector<V> &b, V value, Rest... args){
            b.push_back(value);
            push_args(b, args...);
        }

    public:

        Bector();
        template <typename... Rest>
        Bector(V value, Rest... args){
            size = 0;
            capacity = 1;
            array = new V[capacity];

            push_args(*this, value, args...);
        }
        Bector(V[], int);

        ~Bector();

        int getSize();

        int getCapacity();

        void set(int index, V value);

        V get(int index) const;

        V &at(int index);

        void push_back(V value);

        template <typename T>
        void push_back(const Bector<T>&){
            for(const T v : *this)
                push_back(v);
        }

        void pop_back() const;

        V head() const;

        Bector<V> tail() const;

        V back() const;

        V *begin();

        V *end();


        template <typename T>
        std::function<T(std::function<T(T, V)>)> fold(T value) const{
            return [this, value](std::function<T(T, V)> func){
                if(size <= 0) return value;
                return tail().fold(func(value, head()))(func);
            };
        }

        template <typename T>
        Bector<std::pair<V, T>> zip(Bector<T> other) const{
            if(size <= 0 || other.getSize() <= 0) return Bector<std::pair<V, T>>();

            int minSize = size < other.getSize() ? size : other.getSize();
            Bector<std::pair<V, T>> ret;
            for(int i = 0; i < minSize; i++){
                ret.push_back(std::pair<V, T>(array[i], other[i]));
            }
            return ret;
        }


        V &operator[](int index);

        friend std::ostream &operator<<(std::ostream &os, const Bector<V> &b){
            os << "[";
            for(int i = 0; i < b.size; i++){
                os << b.array[i];
                if(i != b.size-1) os << ", ";
            }
            os << "]";
            return os;
        }
};

#include "Bector.tpp"