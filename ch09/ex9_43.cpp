#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

auto replace(string &s, string const &oldVal, string const &newVal)
{
    for (auto curr = s.begin(); curr <= s.end() - oldVal.size(); )
    {
        if (oldVal == string{curr, curr + oldVal.size()})
        {
            curr = s.erase(curr, curr + oldVal.size());
            curr = s.insert(curr, newVal.cbegin(), newVal.cend());
            curr += newVal.size();
        }
        else
        {
            ++curr;
        }
    }
    return s;
}

int main()
{
    string s{ "To drive straight thru is a foolish, tho courageous act." };
    cout << replace(s, "tho", "though") << endl;
    cout << replace(s, "thru", "through") << endl;
}