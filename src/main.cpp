#include <iostream>

#include <algorithmic/algorithms/sqrt.hpp>

int main() {
    int algorithm = 0;

    while (true) {

        std::cout << "=========================\n";
        std::cout << "Choose an algorithm:\n";
        std::cout << "1. Square Root\n";

        std::cout << "Choose an algorithm: " << '\n';
        std::cin >> algorithm;

        std::cout << '\n';

        switch (algorithm) {
        case 1:
            algorithmic::sqrt_interface();
            break;
        
        default:
            break;
        }
        
    }

    return 0;
}