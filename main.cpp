#include <iostream>
#include "FuncA.h"

int main() {
    FuncA object;

    double x;
    int n;

    std::cout << "Enter the value of x (|x| < 1): ";
    std::cin >> x;

    if (std::abs(x) >= 1.0) {
        std::cerr << "Error: |x| must be less than 1 for convergence!" << std::endl;
        return 1;
    }

    std::cout << "Enter the number of terms (n): ";
    std::cin >> n;

    double result = object.solve(x, n);
    std::cout << "Result of the series sum: " << result << std::endl;

    return 0;
}
