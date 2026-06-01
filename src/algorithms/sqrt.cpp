#include <iostream>
#include <iomanip>

#include "algorithmic/algorithms/sqrt.hpp"

namespace {
    double compute(double x,  int depth, bool show_steps) {
        // Find closest perfect square
        int closestPerfSquare = -1;
        double result = -1.0;

        for (int i = 0; true; i++) {
            int square = i * i;
            if (square < x) continue;
            if (square == x) return i;

            if (square > x) {
                closestPerfSquare = (i - 1) * (i - 1);
                result = double (i - 1);
                break;
            }
        }

        std::cout << std::fixed << std::setprecision(12);

        for (int i = 0; i < depth; i++) {
            std::string iteration_str = std::to_string(i + 1);
            std::cout << "Iteration " << iteration_str << ": " << result << '\n';
            double numerator = x - result * result;
            double denominator = 2 * result;
            result += numerator / denominator;
        }

        return result;
    }
}

namespace algorithmic {
    void sqrt_interface() {
        while (true) {
            double x, depth;
            bool show_steps;

            std::cout << "Please input a positive real number on which to perform the square or -1 to quit: ";
            std::cin >> x;

            if (x == -1) break;

            std::cout << "Show iterations? (y/n): ";
            char show_steps_input;
            std::cin >> show_steps_input;

            if (show_steps_input == 'y') show_steps = true;
            else if (show_steps_input == 'n') show_steps = false;

            std::cout << "Calculation depth: ";
            std::cin >> depth;

            std::cout << '\n';

            double result = compute(x, depth, true);

            std::cout << std::defaultfloat << std::setprecision(6);

            std::cout << "√" << x << " = " << result << "\n\n";
        }
    }
}