/*
 * @Author: liyunfang
 * @Date: 2020-01-28 15:38:22
 * @LastEditTime : 2020-01-28 16:12:32
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

auto init_veci()
{
    return std::make_shared<std::vector<int>>();
}

auto add_elements(std::shared_ptr<std::vector<int>> veci)
{
    std::cout << "Plz input:\n";
    for (int i; std::cin >> i; veci->push_back(i));
    return veci;
}

auto print_veci(std::shared_ptr<std::vector<int>> veci) -> std::ostream&
{
    std::for_each(veci->begin(), veci->end(), [](int const &num){ std::cout << num << " ";});
    return std::cout;
}

int main()
{
    print_veci(add_elements(init_veci())) << std::endl;
}