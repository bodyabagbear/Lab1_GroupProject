#include "shared_types.h"
#include <iostream>

// Наша піддослідна функція f(x) = x^2
double my_function(double x) {
    return x * x;
}

int main() {
    std::cout << "Starting Lab 1 calculations (Variant 1)..." << std::endl;
    
    // Створюємо єдиний екземпляр вхідних даних для обох алгоритмів[cite: 1]
    auto data = std::make_shared<const InputData>(InputData{0.0, 2.0, 100, my_function});

    return 0;
}