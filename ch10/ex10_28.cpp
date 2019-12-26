/*
 * @Author: liyunfang
 * @Date: 2019-12-26 15:28:50
 * @LastEditTime: 2019-12-26 15:36:44
 * @Description: 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using std::list; using std::copy; using std::cout; using std::endl;

template<typename Sequence>
void print(Sequence const& seq)
{
    for (const auto& i : seq)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    list<int> lst1, lst2, lst3;
    copy(vec.cbegin(), vec.cend(), std::inserter(lst1, lst1.begin()));
    copy(vec.cbegin(), vec.cend(), std::back_inserter(lst2));
    copy(vec.cbegin(), vec.cend(), std::front_inserter(lst3));

    print(lst1);
    print(lst2);
    print(lst3);
}