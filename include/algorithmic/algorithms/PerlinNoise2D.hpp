#pragma once

#include <vector>
#include <array>

namespace algorithmic {

    class PerlinNoise2D {
        private:
            double width, height;

            std::vector<std::vector<std::array<double, 2>>> generate_unit_vectors(double period, double amplitude);
        public:

            PerlinNoise2D(double w, double h);
            PerlinNoise2D();

            void interface();

            const double noise(double x, double y);
        


    };
    
}