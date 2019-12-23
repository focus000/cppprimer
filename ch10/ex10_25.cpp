/*
 * @Author: liyunfang
 * @Date: 2019-12-23 12:38:43
 * @LastEditTime : 2019-12-24 00:03:14
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

auto check_size(string const& str, size_t sz)
{
    return str.size() >= sz;
}

auto biggies(vector<string> &words, string::size_type sz)
{
    stable_sort(words.begin(), words.end(), [](string const &str1, string const &str2) { return str1.size() < str2.size(); });
    words.erase(unique(words.begin(), words.end()), words.end());
    auto wc = partition(words.begin(), words.end(), bind(check_size, placeholders::_1, sz));
    cout << "count: " << wc - words.begin() << endl;
    for_each(words.begin(), wc, [](string const &str) { cout << str << " "; });
    cout << endl;
}

int main()
{
    vector<string> v{"1234","1234","1234","hi~", "alan", "alan", "cp"};
    biggies(v, 3);
}