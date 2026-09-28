#ifndef SHARED_TYPES_H
#define SHARED_TYPES_H

#include <functional>

// Структура для зберігання результатів обчислень і метрик порівняння
struct IntegrationResult {
    double value;           // Значення інтеграла
    int function_calls;     // Кількість обчислень функції
    double execution_time_ms; // Час виконання в мілісекундах
};

// Тестова функція для інтегрування, наприклад f(x) = x * x
inline double target_function(double x) {
    return x * x; 
}

#endif // SHARED_TYPES_H