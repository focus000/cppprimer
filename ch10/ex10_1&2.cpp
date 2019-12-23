#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main()
{
    vector<int> veci{2, 3, 2, 2, 6, 7, 23, 2, 6, 8, 12, 55, 2};
    list<string> listr{"un", "sd", "wess", "un", "hello", "undo", "un"};
    cout << std::count(veci.cbegin(), veci.cend(), 2) << endl;
    cout << std::count(listr.cbegin(), listr.cend(), "un") << endl;
}