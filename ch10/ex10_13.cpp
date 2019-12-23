#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::partition;

inline bool
predicate(string const &str)
{
    return str.size() >= 5;
}

int main()
{
    auto v = vector<string>{"a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa"};
    auto pivot = partition(v.begin(), v.end(), predicate);
    for (auto it = v.begin(); it != pivot; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}