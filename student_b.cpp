#include "shared_types.h"

// Функція Студента Б отримує дані через shared_ptr[cite: 1]
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data) {
    double h = (data->b - data->a) / data->n;
    double sum = (data->func(data->a) + data->func(data->b)) / 2.0;
    int calls = 2;

    for (int i = 1; i < data->n; i++) {
        double x = data->a + i * h;
        sum += data->func(x);
        calls++;
    }
    
    double result = sum * h;

    // Повертаємо результат через unique_ptr[cite: 1]
    return std::make_unique<Result>(Result{result, calls});
}