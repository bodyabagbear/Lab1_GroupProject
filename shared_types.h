#pragma once

#include <functional>
#include <memory>

struct InputData {
    double a;
    double b;
    int n;
    std::function<double(double)> func;
};

struct Result {
    double integral_value;
    int function_calls;
};

std::unique_ptr<Result> calculateA(
    std::shared_ptr<const InputData> data);

std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data);