#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::unique;

auto elimDups(vector<int> &vec)
{
    sort(vec.begin(), vec.end());
    auto end_unique = unique(vec.begin(), vec.end());
    vec.erase(end_unique, vec.cend());

    for (auto &&i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> veci{1, 6, 77, 2, 4, 5, 7, 78, 2, 77, 8, 6, 2, 66, 77, 4, 5, 66};
    elimDups(veci);
}