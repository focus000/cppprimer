#include <iostream>
#include <string>
#include <deque>

using std::cout;
using std::endl;
using std::string;
using std::deque;
using std::cin;

int main()
{
    string str;
    deque<string> strdq;

    while (cin >> str)
    {
        strdq.push_back(str);
    }

    for (auto iter = strdq.cbegin(); iter != strdq.cend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}