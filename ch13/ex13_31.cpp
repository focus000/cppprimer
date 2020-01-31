#include "ex13_5_8_11_22_30_31.h"
#include <vector>
#include <algorithm>

int main()
{
    std::vector<HasPtr> vechp{HasPtr("hello"), HasPtr("fucking"), HasPtr("world"), HasPtr("meow")};
    std::sort(vechp.begin(), vechp.end());
}