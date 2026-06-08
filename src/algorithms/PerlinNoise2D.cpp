#include <vector>



namespace algorithmic {
    class PerlinNoise2D {
        private:
            std::vector<std::vector<double[2]>> unit_vectors;

            void generate_unit_vectors(double period, double amplitude) {
                double x = 0;
                double y = 0;
            }

        public:

            PerlinNoise2D(double x, double y) {
                this->width = x;
                this->height = x;
            }

            const double noise(double x, double y) const {

            }
        


    };
}