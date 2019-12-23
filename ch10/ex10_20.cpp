/*
 * @Author: liyunfang
 * @Date: 2019-12-23 23:04:28
 * @LastEditTime : 2019-12-23 23:14:09
 * @Description: 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> v{
        "alan","moophy","1234567","1234567","1234567","1234567"
    };

    cout << count_if(v.cbegin(), v.cend(), [](string const &s){
        return s.size() > 6;
    }) << endl;
}