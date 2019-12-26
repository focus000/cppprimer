/*
 * @Author: liyunfang
 * @Date: 2019-12-26 15:38:35
 * @LastEditTime: 2019-12-26 15:52:05
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int main()
{
    ifstream file("data/letter.txt");
    std::istream_iterator<string> in(file);
    std::istream_iterator<string> end;
    std::ostream_iterator<string> out(cout, " ");
    vector<string> vecstr;
    std::copy(in, end, std::back_inserter(vecstr));
    std::copy(vecstr.cbegin(), vecstr.cend(), out);
}