#include <iostream>

void swap_ptr(int *&p1, int *&p2)
{
    auto tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int main()
{
    int num1 = 3, num2 = 5;
    auto ptr1 = &num1;
    auto ptr2 = &num2;
    swap_ptr(ptr1, ptr2);
    std::cout << *ptr1 << " " << *ptr2 << std::endl;
    return 0;
}