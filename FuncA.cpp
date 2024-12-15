#include "FuncA.h"
#include <cmath>

double FuncA::solve(double x, int n) {
    double sum = 0.0;

    for (int i = 0; i <= n; ++i) {
        sum += std::pow(x, i);
    }

    return sum;
}
