#include "shared_types.h"
#include <stdexcept>

std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data)
{
    if (!data || !data->func) {
        throw std::invalid_argument("Missing input data or function");
    }

    if (data->n <= 0) {
        throw std::invalid_argument(
            "Trapezoidal: n must be positive");
    }

    const double h = (data->b - data->a) / data->n;
    double sum =
        (data->func(data->a) + data->func(data->b)) / 2.0;
    int calls = 2;

    for (int i = 1; i < data->n; ++i) {
        sum += data->func(data->a + i * h);
        ++calls;
    }

    return std::make_unique<Result>(
        Result{sum * h, calls});
}