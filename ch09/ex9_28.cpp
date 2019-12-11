#include <iostream>
#include <forward_list>
#include <string>

using std::cout;
using std::endl;
using std::forward_list;
using std::string;

void forward_listInsert(forward_list<string> &flst, string const &to_find, string const &to_add)
{
    auto prev = flst.before_begin();

    for (auto curr = flst.begin(); curr != flst.end(); prev = curr++)
    {
        if (*curr == to_find)
        {
            flst.insert_after(curr, to_add);
            return;
        }
    }
    flst.insert_after(prev, to_add);
}