#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

auto add_pre_and_suffix(string name, string const &pre, string const &su)
{
    name.insert(name.cbegin(), pre.cbegin(), pre.cend());
    return name.append(su);
}

int main()
{
    string name("Wang");
    cout << add_pre_and_suffix(name, "Mr.", ", Jr.") << endl;
    return 0;
}