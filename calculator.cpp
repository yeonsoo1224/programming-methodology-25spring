#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    if ((b > 0 && a > std::numeric_limits<int>::max() - b) ||
        (b < 0 && a < std::numeric_limits<int>::min() - b)) {
        throw std::overflow_error("Addition overflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    if ((b < 0 && a > std::numeric_limits<int>::max() + b) ||
        (b > 0 && a < std::numeric_limits<int>::min() + b)) {
        throw std::overflow_error("Subtraction overflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    if (a != 0 && b != 0) {
        if ((a == -1 && b == std::numeric_limits<int>::min()) ||
            (b == -1 && a == std::numeric_limits<int>::min())) {
            throw std::overflow_error("Multiplication overflow");
        }
        if (a > std::numeric_limits<int>::max() / b ||
            a < std::numeric_limits<int>::min() / b) {
            throw std::overflow_error("Multiplication overflow");
        }
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a == std::numeric_limits<int>::min() && b == -1) {
        throw std::overflow_error("Division overflow");
    }
    return a / b;
}