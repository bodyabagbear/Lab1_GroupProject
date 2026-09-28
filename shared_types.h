#pragma once
#include <memory>
#include <functional>

// Спільні вхідні дані для варіанта 1
struct InputData {
    double a; // початок інтервалу
    double b; // кінець інтервалу
    int n;    // кількість розбиттів
    std::function<double(double)> func; // функція f(x), яку інтегруємо
};

// Структура для результату
struct Result {
    double integral_value; 
    int function_calls;  
};

// Оголошення ваших функцій
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);