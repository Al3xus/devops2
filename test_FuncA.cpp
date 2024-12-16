#include <iostream>
#include <cassert>
#include <cmath>
#include <chrono>
#include "FuncA.h"


void test_factorial() {
    FuncA obj;
    const int largeNumber = 10000;
    long long result;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1e6; ++i) { // Повторення обчислень 1 мільйон разів
        result = obj.factorial(largeNumber);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    assert(elapsed.count() >= 5.0 && elapsed.count() <= 20.0);
    std::cout << "Performance test passed! Time: " << elapsed.count() << " seconds." << std::endl;
}

int main() {
    test_factorial();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
