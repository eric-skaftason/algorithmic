#pragma once
#include "algorithmic/algorithms/PerlinNoise2D.hpp"

#include <vector>

namespace algorithmic {

    class PerlinNoise2D {
        private:
            std::vector<std::vector<double[2]>> unit_vectors;
            double width, height;

            void generate_unit_vectors(double period, double amplitude);
        public:

            PerlinNoise2D();

            const double noise(double x, double y) const;
        


    };
    
}