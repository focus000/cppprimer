#include <iostream>
#include <list>
#include <deque>

using std::cout;
using std::deque;
using std::endl;
using std::list;

int main()
{
    list<int> il{33, 56, 23, 87, 23, 90, 234};
    deque<int> odd, even;
    for (auto &&i : il)
    {
        (i % 2) ? odd.push_back(i) : even.push_back(i);
    }

    for (auto &&i : odd)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto &&i : even)
    {
        cout << i << " ";
    }
    cout << endl;
}