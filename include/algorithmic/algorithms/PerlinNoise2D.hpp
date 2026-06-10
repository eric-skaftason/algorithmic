#pragma once

#include <vector>
#include <array>

using UnitVector = std::array<double, 2>;
using UnitVectorRow = std::vector<UnitVector>;
using NoiseOctave = std::vector<UnitVectorRow>;
using NoiseMap = std::vector<NoiseOctave>;

namespace algorithmic {

    class PerlinNoise2D {
        private:
            double width, height;
            double init_period, init_amplitude;

            int octaves;

            NoiseMap map;

            NoiseOctave generate_octave(int rows, int cols, double amplitude);

            const void generate_map(double init_period, double init_amplitude, int octaves);
            const double sample_noise(double x, double y);
            
        public:

            PerlinNoise2D(double w, double h, double init_period, double init_amplitude, int octaves);

            void interface();
        


    };
    
}