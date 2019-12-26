/*
 * @Author: liyunfang
 * @Date: 2019-12-26 16:02:02
 * @LastEditTime: 2019-12-26 20:51:04
 * @Description: 
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    std::istream_iterator<int> in(cin), eof;
    std::ostream_iterator<int> out(cout, " ");
    std::vector<int> veci;
    std::copy(in, eof, std::back_inserter(veci));
    std::sort(veci.begin(), veci.end());
    std::copy(veci.begin(), veci.end(), out);
    cout << endl;
}