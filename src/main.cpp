#include <iostream>

#include <algorithmic/algorithms/sqrt.hpp>
#include <algorithmic/algorithms/PerlinNoise2D.hpp>


algorithmic::PerlinNoise2D noise(50, 50);

int main() {
    int algorithm = 0;

    while (true) {

        std::cout << "=========================\n";
        std::cout << "Choose an algorithm:\n";
        std::cout << "1. Square Root\n";
        std::cout << "2. Perlin Noise (2D)\n";

        std::cout << "Choose an algorithm: " << '\n';
        std::cin >> algorithm;

        std::cout << '\n';

        switch (algorithm) {
        case 1:
            algorithmic::sqrt_interface();
            break;
        
        case 2:
            
            noise.interface();
            break;
        
        default:
            break;
        }
        
    }

    return 0;
}