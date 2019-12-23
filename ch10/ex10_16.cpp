/*
 * @Author: liyunfang
 * @Date: 2019-12-23 12:38:43
 * @LastEditTime : 2019-12-23 14:11:03
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

auto biggies(vector<string> &words, string::size_type sz)
{
    stable_sort(words.begin(), words.end(), [](string const &str1, string const &str2) { return str1.size() < str2.size(); });
    words.erase(unique(words.begin(), words.end()), words.end());
    auto wc = find_if(words.begin(), words.end(), [sz](string const &str) { return str.size() >= sz; });
    cout << "count: " << words.end() - wc << endl;
    for_each(wc, words.end(), [](string const &str) { cout << str << " "; });
    cout << endl;
}

int main()
{
    vector<string> v{"1234","1234","1234","hi~", "alan", "alan", "cp"};
    biggies(v, 3);
}