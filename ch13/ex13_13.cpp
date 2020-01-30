/*
 * @Author: liyunfang
 * @Date: 2020-01-30 17:14:59
 * @LastEditTime : 2020-01-30 17:17:16
 * @Description: copy from https://github.com/Mooophy/Cpp-Primer/blob/master/ch13/ex13_13.cpp
 */
#include <iostream>
#include <vector>
#include <initializer_list>

struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(const X &rx, X x)
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    vec.push_back(x);
}

int main()
{
    X *px = new X;
    f(*px, *px);
    delete px;

    return 0;
}