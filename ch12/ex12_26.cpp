/*
 * @Author: liyunfang
 * @Date: 2020-01-29 16:11:14
 * @LastEditTime : 2020-01-29 16:25:48
 * @Description: 
 */
#include <memory>
#include <string>
#include <iostream>

auto func(int n)
{
    std::allocator<std::string> allocstr;
    auto const p = allocstr.allocate(n);
    std::string s;
    auto q = p;
    while (std::cin >> s && q != p + n)
    {
        allocstr.construct(q++, s);
    }
    size_t const size = q - p;
    while (q != p)
    {
        std::cout << *--q << " ";
        allocstr.destroy(q);
    }
    std::cout << std::endl;
    allocstr.deallocate(p, n);
}

int main()
{
    func(7);
}