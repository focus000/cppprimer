#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::string;
using std::unique;

auto elimDups(vector<string> &vecstr)
{
    sort(vecstr.begin(), vecstr.end());
    auto end_unique = unique(vecstr.begin(), vecstr.end());
    vecstr.erase(end_unique, vecstr.cend());

    for (auto &&i : vecstr)
    {
        cout << i << " ";
    }
    cout << endl;
}

inline bool
isShorter (string const &s1, string const &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> vstr{"1234", "1234", "1234", "Hi", "alan", "wang"};
    elimDups(vstr);
    std::stable_sort(vstr.begin(), vstr.end(), isShorter);
    for (auto &&i : vstr)
    {
        cout << i << " ";
    }
    cout << endl;
}