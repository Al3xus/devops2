#include <iostream>
#include <cmath>

int CreateHTTPserver();

int main() {
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

    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += std::pow(x, i);
    }

    std::cout << "Result of the series sum: " << result << std::endl;
    CreateHTTPserver();
    return 0;
}
