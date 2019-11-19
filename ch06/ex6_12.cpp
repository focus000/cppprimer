#include <iostream>

void swap_ref(int &lhs, int &rhs)
{
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main()
{
    int m = 5, n = 12;
    swap_ref(m, n);
    std::cout << m << "\n"
              << n << std::endl;
    return 0;
}