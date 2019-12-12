#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

auto replace(string &s, string const &oldVal, string const &newVal)
{
    for (size_t pos = 0; pos <= s.size() - oldVal.size();)
    {
        if (oldVal[0] == s[pos] && oldVal == s.substr(pos, oldVal.size()))
        {
            s.replace(pos, oldVal.size(), newVal);
            pos += newVal.size();
        }
        else
        {
            ++pos;
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