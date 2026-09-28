#include "shared_types.h"

// Функція Студента А отримує дані через shared_ptr
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    int n = data->n;
    // Для методу Сімпсона кількість розбиттів має бути парною[cite: 1]
    if (n % 2 != 0) {
        n++; 
    }

    double h = (data->b - data->a) / n;
    double sum = data->func(data->a) + data->func(data->b);
    int calls = 2; 

    for (int i = 1; i < n; i++) {
        double x = data->a + i * h;
        if (i % 2 == 0) {
            sum += 2 * data->func(x);
        } else {
            sum += 4 * data->func(x);
        }
        calls++;
    }
    
    double result = (h / 3.0) * sum;

    // Повертаємо результат через unique_ptr[cite: 1]
    return std::make_unique<Result>(Result{result, calls});
}