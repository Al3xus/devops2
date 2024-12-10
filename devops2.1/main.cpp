#include <iostream>
#include "FuncA.h"

int main() {
    FuncA object;
    int n = 10;
    std::cout << "Result of FuncA: " << object.solve(n) << std::endl;
    return 0;
}