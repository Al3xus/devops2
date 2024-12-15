#include <iostream>
#include <cassert>
#include <cmath>
#include "FuncA.h"

void test_factorial() {
    FuncA obj;
    assert(obj.factorial(0) == 1);
    assert(obj.factorial(1) == 1);
    assert(obj.factorial(5) == 120);
    assert(obj.factorial(10) == 3628800);
}


void test_solve() {
    FuncA obj;
    double x = 0.5;

    double result = obj.solve(x, 5);
    double expected = 1 / (1 - x);
    assert(std::abs(result - expected) < 1e-6);

    result = obj.solve(0.3, 100);
    expected = 1 / (1 - 0.3);
    assert(std::abs(result - expected) < 1e-6);
}


int main() {
    test_factorial();
    test_solve();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
