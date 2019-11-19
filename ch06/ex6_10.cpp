#include <iostream>

void swap_ints(int *fp, int *bp)
{
    int tmp = *fp;
    *fp = *bp;
    *bp = tmp;
}

int main()
{
    int m = 5, n = 12;
    swap_ints(&m, &n);
    std::cout << m << "\n"
              << n << std::endl;
    return 0;
}