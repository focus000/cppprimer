#include <iostream>

void print(const int &ri)
{
    std::cout << ri << std::endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        std::cout << *beg++ << std::endl;
    }
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print(i);
    print(std::begin(j), std::end(j));
    return 0;
}