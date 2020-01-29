/*
 * @Author: liyunfang
 * @Date: 2020-01-29 14:23:32
 * @LastEditTime : 2020-01-29 14:50:21
 * @Description: 
 */
#include <iostream>
#include <cstring>
#include <string>

int main()
{
    auto p = new char[strlen("hello" "world") + 1]();
    strcat(p, "hello ");
    strcat(p, "world");
    std::cout << p << std::endl;
    delete[] p;
    std::cout << std::string{"hello "} + std::string{"world"} << std::endl;
}