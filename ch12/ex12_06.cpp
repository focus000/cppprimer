/*
 * @Author: liyunfang
 * @Date: 2020-01-28 14:41:33
 * @LastEditTime : 2020-01-28 15:26:06
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <algorithm>

auto init_veci()
{
    return new std::vector<int>();
}

auto add_elements(std::vector<int> *veci)
{
    int tmp;
    while (std::cin)
    {
        std::cin >> tmp;
        veci->push_back(tmp);
    }
    return veci;
}

auto print_veci(std::vector<int> *veci) -> std::ostream&
{
    std::for_each(veci->begin(), veci->end(), [](int const &num){ std::cout << num << " ";});
    return std::cout;
}

int main()
{
    auto p = add_elements(init_veci());
    print_veci(p) << std::endl;
    delete p;
}