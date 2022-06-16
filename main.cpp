#include <iostream>
#include "Bector.hpp"

using namespace std;

template <typename T>
void print(T a, char e = '\n'){
    cout << a << e;
}

#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));

    printf("Hey!");

    fwrite("Meow\n", 4, 1, stdout);

}