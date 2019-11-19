#include <iostream>

int max(const int num, const int *const ptrnum)
{
    return num > *ptrnum ? num : *ptrnum;
}

int main()
{
    int num1 = -1, num2 = -0;
    std::cout << max(num1, &num2) << std::endl;
}