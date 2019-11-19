#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> li)
{
    int s = 0;
    for (const auto &r : li)
    {
        s += r;
    }
    return s;
}

int main()
{
    std::cout << sum({1, 2, 3, 4}) <<std::endl;
    return 0;
}