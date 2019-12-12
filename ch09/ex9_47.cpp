#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

auto find_first_of_version(string const &s)
{
    string numbers{"0123456789"};
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string::size_type pos = 0;
    while ((pos = s.find_first_of(numbers, pos)) != string::npos)
    {
        cout << pos << " " << s[pos] << endl;
        ++pos;
    }
    cout << "=================" << endl;
    pos = 0;
    while ((pos = s.find_first_of(alphabet, pos)) != string::npos)
    {
        cout << pos << " " << s[pos] << endl;
        ++pos;
    }
}

auto find_first_not_of_version(string const &s)
{
    string numbers{"0123456789"};
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string::size_type pos = 0;
    while ((pos = s.find_first_not_of(alphabet, pos)) != string::npos)
    {
        cout << pos << " " << s[pos] << endl;
        ++pos;
    }
    cout << "=================" << endl;
    pos = 0;
    while ((pos = s.find_first_not_of(numbers, pos)) != string::npos)
    {
        cout << pos << " " << s[pos] << endl;
        ++pos;
    }
}

int main()
{
    string s{"ab2c3d7R4E6"};
    cout << "find_first_of: \n";
    find_first_of_version(s);
    cout << "find_first_not_of: \n";
    find_first_not_of_version(s);
}