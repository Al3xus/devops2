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

int main() {
    test_factorial();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}