#include <iostream>
#include <forward_list>

using std::cout;
using std::endl;
using std::forward_list;

int main()
{
    int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    forward_list<int> fli(std::begin(a), std::end(a));
    auto prev = fli.before_begin();
    auto curr = fli.begin();

    while (curr != fli.end())
    {
        if (*curr % 2)
        {
            curr = fli.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for (auto &&i : fli)
    {
        cout << i << " ";
    }
    cout << endl;
}