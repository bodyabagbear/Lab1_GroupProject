#include "shared_types.h"

#include <chrono>
#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <vector>

double my_function(double x) {
    return x * x;
}

int main() {
    using Clock = std::chrono::steady_clock;

    const std::vector<int> subdivisions{10, 100, 1000};
    const double exact_value = 1.0 / 3.0;

    std::cout << std::setprecision(12);
    std::cout << "Variant 1: f(x) = x^2, interval [0, 1]\n";
    std::cout << "Exact integral: " << exact_value << '\n';

    try {
        for (int n : subdivisions) {
            // Обидва методи отримують один спільний об'єкт.
            auto data = std::make_shared<const InputData>(
                InputData{0.0, 1.0, n, my_function});

            const auto startA = Clock::now();
            auto resultA = calculateA(data);
            const auto endA = Clock::now();

            const auto startB = Clock::now();
            auto resultB = calculateB(data);
            const auto endB = Clock::now();

            // Структуровані прив'язки.
            auto [valueA, callsA] = *resultA;
            auto [valueB, callsB] = *resultB;

            const double timeA =
                std::chrono::duration<double, std::milli>(
                    endA - startA).count();

            const double timeB =
                std::chrono::duration<double, std::milli>(
                    endB - startB).count();

            std::cout << "\nn = " << n << '\n';

            std::cout << "Simpson:\n"
                      << "  Integral: " << valueA << '\n'
                      << "  Absolute error: "
                      << std::abs(valueA - exact_value) << '\n'
                      << "  Function calls: " << callsA << '\n'
                      << "  Time (ms): " << timeA << '\n';

            std::cout << "Trapezoidal:\n"
                      << "  Integral: " << valueB << '\n'
                      << "  Absolute error: "
                      << std::abs(valueB - exact_value) << '\n'
                      << "  Function calls: " << callsB << '\n'
                      << "  Time (ms): " << timeB << '\n';
        }
    }
    catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }

    return 0;
}