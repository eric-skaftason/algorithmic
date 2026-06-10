#include <iostream>
#include <vector>
#include <array>

#include <random>
#include <cmath>

#include "algorithmic/algorithms/PerlinNoise2D.hpp"

// Hardware Entropy Source
std::random_device rd;

// create the Mersenne Twister object, named gen, passing in a random seed from the hardware device
std::mt19937 gen(rd());

// range for full circle in radians
std::uniform_real_distribution<double> dist(0.0, 2.0 * M_PI);

namespace algorithmic {

    std::vector<std::vector<std::array<double, 2>>> PerlinNoise2D::generate_unit_vectors(double period, double amplitude) {
        double x = 0;
        double y = 0;

        std::vector<std::vector<std::array<double, 2>>> unit_vectors;

        // Iterate throught each grid point
        for (int row = 0; row * period <= this->height; row++) {
            std::vector<std::array<double, 2>> row_vectors;
            for (int col = 0; col * period <= this->width; col++) {
                // create unit vector

                double random_angle = dist(gen);

                double x = std::cos(random_angle);
                double y = std::sin(random_angle);

                std::array<double, 2> unit_vector = {x, y};

                row_vectors.push_back(unit_vector);

            }

            unit_vectors.push_back(row_vectors);
        }

        return unit_vectors;
    }

    void PerlinNoise2D::interface() {
        std::vector<std::vector<std::array<double, 2>>> unit_vectors = generate_unit_vectors(10.0, 1.0);

        for (int i = 0; i < unit_vectors.size(); i++) {
            for (int j = 0; j < unit_vectors[i].size(); j++) {
                std::array<double, 2> unit_vector = unit_vectors[i][j];

                std::cout << '[' << unit_vector[0] << ' ' << unit_vector[1] << "] ";
            }
            std::cout << '\n';
        }
    }


    PerlinNoise2D::PerlinNoise2D(double w, double h) {
        this->width = w;
        this->height = h;
    }

    PerlinNoise2D::PerlinNoise2D() {
        std::cout << "\nEnter width: ";
        std::cin >> this->width;

        std::cout << "Enter height: ";
        std::cin >> this->height;

        std::cout << "Ready! \n\n";
    }

    const double PerlinNoise2D::noise(double x, double y) {
        std::vector<std::vector<std::array<double, 2>>> unit_vectors = generate_unit_vectors(10.0, 1.0);

        for (int i = 0; i < unit_vectors.size(); i++) {
            for (int j = 0; j < unit_vectors[i].size(); j++) {
                std::array<double, 2> unit_vector = unit_vectors[i][j];

                std::cout << '[' << unit_vector[0] << ' ' << unit_vector[1] << "] ";
            }
            std::cout << '\n';
        }
    }
        
}