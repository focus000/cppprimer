#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::cin;

int main()
{
    string str;
    list<string> strdq;

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