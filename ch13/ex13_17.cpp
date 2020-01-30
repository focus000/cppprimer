/*
 * @Author: liyunfang
 * @Date: 2020-01-30 19:53:59
 * @LastEditTime : 2020-01-30 20:36:18
 * @Description: 
 */
#include <iostream>

class numbered
{
    public:
    numbered() : mysn(unique++) { }
    numbered(numbered const &num) : mysn(unique++) { }
    int mysn;
    static int unique;
};

int numbered::unique = 0;

auto f (numbered const &s) { std::cout << s.mysn << std::endl; }

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}
// 0 0 0
// 3 4 5
// 0 1 2