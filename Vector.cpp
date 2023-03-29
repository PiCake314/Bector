#include <iostream>
#include "Bector.hpp"


int main(){
    Bector<int> b1(1, 2, 3, 4, 5);
    
    Bector<std::string> b2("Ali", "Pie", "Meow");

    Bector b3('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i');

    // std::cout << b1 << std::endl;
    // std::cout << b2 << std::endl;

    Bector b4 = b1.zip(b2).zip(b3);

    for(auto [t, c] : b4){
        auto [a, b] = t;
        std::cout << a << " " << b << " " << c << std::endl;
    }

}