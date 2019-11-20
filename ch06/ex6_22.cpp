#include <iostream>

typedef const int *const_str;

void swap_ptr(const_str&p1, const_str&p2)
{
    auto tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void swap_ptr(int *&p1, int *&p2)
{
    swap_ptr(const_cast<const_str &>(p1), const_cast<const_str &>(p2));
}

int main()
{
    int num1 = 3, num2 = 5;
    int * ptr1 = &num1;
    int * ptr2 = &num2;
    swap_ptr(ptr1, ptr2);
    std::cout << *ptr1 << " " << *ptr2 << std::endl;
    return 0;
}