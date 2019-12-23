/*
 * @Author: liyunfang
 * @Date: 2019-12-23 23:14:25
 * @LastEditTime : 2019-12-23 23:29:41
 * @Description: 
 */
#include <iostream>

int main()
{
    int i = 7;
    auto check_and_decrement = [&i]() -> bool {
        return i > 0 ? !--i : !i;
    };
    while (!check_and_decrement())
    {
        std::cout << i << " ";
    }
    std::cout << i << std::endl;
}