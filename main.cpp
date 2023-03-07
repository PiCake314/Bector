#include <iostream>
#include "Bector.hpp"

int main(){

    Bector<std::string> b;

    b.push_back("I");
    b.push_back("Love");
    b.push_back("CSCI");
    b.push_back("3155");
    b.push_back("!");


    for(const auto &elt : b){
        std::cout << elt;
        if(elt != b.back()) std::cout << ", ";
    }
    std::cout << '\n';






    // std::string cat = b.fold<std::string>("")([](std::string acc, std::string elt){ return acc + elt + " "; });
    // std::cout << "Cat: " << cat << std::endl;

    
    // int length = b.fold(0)(
    //     [](int acc, std::string elt){
    //         return acc + elt.length();
    //     }
    // );
    // std::cout << "Length: " << length << std::endl;


    // std::string word = b.fold<std::string>("")(
    //     [](std::string acc, std::string elt){
    //         if(elt.length() >= acc.length())return elt;
    //         else return acc; 
    //     }
    // );
    // std::cout << "Longest Word: " << word << std::endl;


}