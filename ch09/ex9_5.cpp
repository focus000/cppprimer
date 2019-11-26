#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

auto func(vector<int>::const_iterator &iter1, vector<int>::const_iterator &iter2, const int num)
{
    auto liter = (iter1 <= iter2) ? iter1 : iter2;
    auto riter = (iter1 <= iter2) ? iter2 : iter1;

    for (; liter != riter; ++liter)
    {
        if (*liter == num)
        {
            return liter;
        }
    }
    return riter;
}