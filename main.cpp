#include <iostream>
#include "shared_types.h"

// Оголошення функції студента А (метод Симпсона)
IntegrationResult calculate_simpson(double a, double b, int n);

int main() {
    std::cout << "=== LAB 1: NUMERICAL INTEGRATION ===" << std::endl;

    double a = 0.0; // Нижня межа інтегрування
    double b = 1.0; // Верхня межа інтегрування
    int n = 100;    // Кількість розбиттів (має бути парним для методу Симпсона)

    std::cout << "Interval: [" << a << ", " << b << "], n = " << n << std::endl;

    try {
        // Виклик методу Симпсона (Студент А)
        IntegrationResult simpson_res = calculate_simpson(a, b, n);

        std::cout << "\n--- Student A (Simpson's Method) ---" << std::endl;
        std::cout << "Integral Value: " << simpson_res.value << std::endl;
        std::cout << "Function Calls: " << simpson_res.function_calls << std::endl;
        std::cout << "Execution Time: " << simpson_res.execution_time_ms << " ms" << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}