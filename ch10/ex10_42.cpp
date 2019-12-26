/*
 * @Author: liyunfang
 * @Date: 2019-12-26 22:32:16
 * @LastEditTime: 2019-12-26 22:36:18
 * @Description: 
 */
#include <iostream>
#include <list>
#include <string>

using std::string;
using std::list;

void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}

int main()
{
    list<string> l = { "aa", "aa", "aa", "aa", "aasss", "aa" };
    elimDups(l);
    for (const auto& e : l)
        std::cout << e << " ";
    std::cout << std::endl;
}