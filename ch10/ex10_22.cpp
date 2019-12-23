/*
 * @Author: liyunfang
 * @Date: 2019-12-23 23:04:28
 * @LastEditTime : 2019-12-23 23:33:37
 * @Description: 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

auto isShorterthan6(string const &str)
{
    return str.size() <= 6 ? true : false;
}

int main()
{
    vector<string> v{
        "alan","moophy","1234567","1234567","1234567","1234567"
    };

    cout << count_if(v.cbegin(), v.cend(), isShorterthan6) << endl;
}