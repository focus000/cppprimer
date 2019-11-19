#include <iostream>
#include <string>

using std::string;

bool isUpper(const string &s)
{
    for (auto &c : s)
    {
        if (isupper(c))
        {
            return true;
        }
    }
    return false;
}

void toLower(string &s)
{
    for (auto &c : s)
    {
        c = tolower(c);
    }
}

int main()
{
    string str("Hello World");
    string str_modify(str);
    string str_void;

    toLower(str_modify);
    toLower(str_void);


    std::cout << isUpper(str) << "\n"
              << str_modify << "\n"
              << isUpper("") << "\n"
              << str_void << std::endl;
}