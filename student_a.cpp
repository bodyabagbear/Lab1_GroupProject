#include "shared_types.h"
#include <iostream>
#include <chrono>
#include <stdexcept>

// Функція для обчислення інтеграла методом Симпсона (Студент А)
IntegrationResult calculate_simpson(double a, double b, int n) {
    if (n % 2 != 0) {
        throw std::invalid_argument("Error: For Simpson's method, 'n' must be an even number!");
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    double h = (b - a) / n;
    double sum = target_function(a) + target_function(b);
    int func_calls = 2; // Викликали для а та b

    // Непарні індекси (коефіцієнт 4)
    for (int i = 1; i < n; i += 2) {
        sum += 4.0 * target_function(a + i * h);
        func_calls++;
    }

    // Парні індекси (коефіцієнт 2)
    for (int i = 2; i < n; i += 2) {
        sum += 2.0 * target_function(a + i * h);
        func_calls++;
    }

    double result = (h / 3.0) * sum;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end_time - start_time;

    return {result, func_calls, elapsed.count()};
}