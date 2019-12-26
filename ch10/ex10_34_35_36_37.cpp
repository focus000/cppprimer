/*
 * @Author: liyunfang
 * @Date: 2019-12-26 21:22:34
 * @LastEditTime : 2019-12-26 22:16:41
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main()
{
    std::ostream_iterator<int> out(std::cout, " ");
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::copy(vec.crbegin(), vec.crend(), out);
    std::cout << std::endl;

    for (auto it = std::prev(vec.cend()); it != std::prev(vec.cbegin()); --it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::list<int> lst = { 1, 2, 3, 4, 0, 5, 6 };
    auto find_0 = std::find(lst.crbegin(), lst.crend(), 0);
    std::cout << std::distance(find_0, lst.crend()) << std::endl;

    std::list<int> ret_lst(8 - 3);
    std::copy(vec.cbegin() + 3, vec.cbegin() + 8, ret_lst.rbegin());
    std::copy(ret_lst.cbegin(), ret_lst.cend(), out);
    std::cout << std::endl;
}