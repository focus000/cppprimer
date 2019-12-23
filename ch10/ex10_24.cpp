/*
 * @Author: liyunfang
 * @Date: 2019-12-23 23:40:04
 * @LastEditTime : 2019-12-23 23:57:59
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

auto check_size(string const& str, size_t sz)
{
    return str.size() < sz;
}

int main()
{
    vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7 };
    string str("");
    auto result = find_if(vec.cbegin(), vec.cend(), bind(check_size, str, placeholders::_1));
    if (result != vec.end())
    {
        cout << *result << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}