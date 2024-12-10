#include "FuncA.h"
#include <cmath> 


int FuncA::solve(int n) {
    double x = 1.0;  
    double sum = 0.0; 
    int sign = 1;  

    for (int i = 0; i < n; ++i) {
        int termIndex = 2 * i + 1; 
        double term = sign * std::pow(x, termIndex) / factorial(termIndex);
        sum += term;
        sign = -sign;  
    }

    return static_cast<int>(sum); 
}

int FuncA::factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}