import callbackModule;
import <cmath>;
import <iostream>;
import std;

template <typename F>
double first_derivative(F func, double x, double step) {
    return (func(x + step) - func(x)) / step;
}

template <typename F>
double min_deriv(F func, double start, double end, double step) {
    double min_derivative = INFINITY;

    for (double x = start; x <= end; x += step) {
        double derivative = first_derivative(func, x, step);

        if (derivative < min_derivative) {
            min_derivative = derivative;
        }
    }

    return min_derivative;
}

int main() {
    double start = -10.0;
    double end = 10.0;
    double step = 0.1;

    auto function1 = [](double x) { return x * x; };
    auto function2 = [](double x) { return std::sin(x); };

    double min_derivative1 = min_deriv(function1, start, end, step);
    std::cout << "Minimum value of the first derivative of x^2: " << min_derivative1 << std::endl;

    double min_derivative2 = min_deriv(function2, start, end, step);
    std::cout << "Minimum value of the first derivative of sin: " << min_derivative2 << std::endl;

    return 0;
}
