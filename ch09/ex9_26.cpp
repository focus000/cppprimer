#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
    int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    list<int> li(std::begin(a), std::end(a));
    vector<int> vi(std::begin(a), std::end(a));
    auto lt = li.begin();
    auto vt = vi.begin();

    while (lt != li.end())
    {
        if (*lt % 2)
        {
            lt = li.erase(lt);
        }
        else
        {
            ++lt;
        }
    }

    while (vt != vi.end())
    {
        if (*vt % 2)
        {
            ++vt;
        }
        else
        {
            vt = vi.erase(vt);
        }
    }

    for (auto &&i : li)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto &&i : vi)
    {
        cout << i << " ";
    }
    cout << endl;
}