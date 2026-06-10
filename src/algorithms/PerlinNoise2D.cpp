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

    NoiseOctave PerlinNoise2D::generate_octave(int rows, int cols, double amplitude) {

        NoiseOctave noise_octave;

        // Iterate through each grid point
        for (int row = 0; row < rows; row++) {
            UnitVectorRow row_vectors;
            for (int col = 0; col < cols; col++) {
                // create unit vector

                double random_angle = dist(gen);

                double x = std::cos(random_angle) * amplitude;
                double y = std::sin(random_angle) * amplitude;

                // std::cout << random_angle << ' ' << dist.min() << ' ' << dist.max() << ' ' << 2.0 * M_PI << '\n';

                UnitVector unit_vector = {x, y};

                row_vectors.push_back(unit_vector);

            }

            noise_octave.push_back(row_vectors);
        }

        return noise_octave;
    }

    void PerlinNoise2D::interface() {
        UnitVector vct = this->map[0][0][0];
        std::cout << vct[0] << ' ' << vct[1] << '\n';
        // for (int oct = 0; oct < this->octaves; oct++) {
        //     for (int i = 0; i < this->map[oct].size(); i++) {
        //         for (int j = 0; j < this->map[oct][i].size(); j++) {
        //             std::array<double, 2> unit_vector = this->map[oct][i][j];

        //             std::cout << '[' << unit_vector[0] << ' ' << unit_vector[1] << "] ";
        //         }
        //         std::cout << '\n';
        //     }
        // }
        
    }


    PerlinNoise2D::PerlinNoise2D(double w, double h, double init_period, double init_amplitude, int octaves) {
        this->width = w;
        this->height = h;

        this->init_period = init_period;
        this->init_amplitude = init_amplitude;

        this->octaves = octaves;

        generate_map(init_period, init_amplitude, octaves);

    }



    const void PerlinNoise2D::generate_map(double period, double amplitude, int octaves) {
        // if (octaves == 0) return;
        
        // generate unit vectors at each intersection point
        int rows = std::floor(this->height / period) + 1;
        int cols = std::floor(this->width / period) + 1;

        NoiseOctave noise_octave = generate_octave(rows, cols, amplitude);

        this->map.push_back(noise_octave);
        
        // generate_map(period / 2, amplitude / 2, --octaves);
    }

    const double PerlinNoise2D::sample_noise(double x, double y) {
        
    }
        
}