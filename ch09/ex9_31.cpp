#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

int main()
{
    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = li.begin();
    while (iter != li.end())
    {
        if (*iter & 0x1)
        {
            iter = li.insert(iter, *iter);
            std:advance(iter, 2);
        }
        else
        {
            iter = li.erase(iter);
        }
    }
    
    for (auto &&i : li)
    {
        cout << i << " ";
    }
    cout << endl;
}