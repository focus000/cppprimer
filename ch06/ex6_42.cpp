#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    for (size_t i = 1; i < 3; ++i)
    {
        cout << make_plural(i, "success") << " "
            << make_plural(i, "failure") << endl;
    }
    return 0;
}