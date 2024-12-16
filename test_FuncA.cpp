#include <iostream>
#include <cassert>
#include <cmath>
#include <chrono>
#include "FuncA.h"

int CreateHTTPserver();

void test_factorial() {
    FuncA obj;
    const int largeNumber = 20;
    auto start = std::chrono::high_resolution_clock::now();
    long long result = obj.factorial(largeNumber);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    assert(result == 2432902008176640000LL);
    assert(elapsed.count() >= 5.0 && elapsed.count() <= 20.0);
    std::cout << "Performance test passed! Time: " << elapsed.count() << " seconds." << std::endl;
}

int main() {
    test_factorial();
    std::cout << "All tests passed!" << std::endl;
    CreateHTTPserver();
    return 0;
}
