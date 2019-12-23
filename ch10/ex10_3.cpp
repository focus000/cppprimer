#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> ele{1, 2, 3, 4, 5 ,6, 7, 8, 9};
    std::cout << std::accumulate(ele.cbegin(), ele.cend(), 0) << std::endl;
}