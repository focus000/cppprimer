#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> veci{12, 3, 5, 6, 5657, 54, 4};
    std::fill_n(veci.begin(), veci.size(), 0);
    for (auto &&i : veci)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}