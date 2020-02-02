#include "HasPtr.h"
#include <chrono>
#include <iostream>
#include <vector>

using namespace std::chrono;

int main()
{
    HasPtr hp1("hello"), hp2("World"), *pH = new HasPtr("World");
    auto t0 = high_resolution_clock::now();
    hp1 = hp2;
    hp1 = std::move(*pH);
    auto t1 = high_resolution_clock::now();
    std::cout << duration_cast<microseconds>(t1-t0).count() << "ms" << std::endl;
}