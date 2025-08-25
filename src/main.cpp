#include <iostream>
#include "myvector.h"

int main (void){
    myvector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    
    std::cout << "Vector: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}