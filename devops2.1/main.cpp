#include <iostream>
#include "FuncA.h"

int main() {
    FuncA object;
    int n = 3;
    std::cout << "Result of FuncA: " << object.solve(n) << std::endl;
    return 0;
}