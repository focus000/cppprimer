/*
 * @Author: liyunfang
 * @Date: 2020-01-29 15:05:19
 * @LastEditTime : 2020-01-29 15:06:03
 * @Description: copy from https://github.com/Mooophy/Cpp-Primer/blob/master/ch12/ex12_24.cpp
 */
#include <iostream>

int main()
{
    // need to tell the size.
    std::cout << "How long do you want the string? ";
    int size{ 0 };
    std::cin >> size;
    char *input = new char[size+1]();
    std::cin.ignore();
    std::cout << "input the string: ";
    std::cin.get(input, size+1);
    std::cout << input;
    delete [] input;
    // Test: if longer than the array size, we will lost the characters which are out of range.
}