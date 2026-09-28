#include "shared_types.h"
#include <stdexcept>

std::unique_ptr<Result> calculateA(
    std::shared_ptr<const InputData> data)
{
    if (!data || !data->func) {
        throw std::invalid_argument("Missing input data or function");
    }

    if (data->n <= 0 || data->n % 2 != 0) {
        throw std::invalid_argument(
            "Simpson: n must be positive and even");
    }

    const double h = (data->b - data->a) / data->n;
    double sum = data->func(data->a) + data->func(data->b);
    int calls = 2;

    for (int i = 1; i < data->n; i += 2) {
        sum += 4.0 * data->func(data->a + i * h);
        ++calls;
    }

    for (int i = 2; i < data->n; i += 2) {
        sum += 2.0 * data->func(data->a + i * h);
        ++calls;
    }

    return std::make_unique<Result>(
        Result{sum * h / 3.0, calls});
}