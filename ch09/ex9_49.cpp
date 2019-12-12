#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main()
{
    string const alpha{"weruioaszxcvnm"};

    ifstream ifs("./data/letter.txt");
    if (!ifs) return -1;

    string longest;
    for (string str; ifs >> str ;)
    {
        if (string::npos == str.find_first_not_of(alpha))
        {
            // cout << str << " ";
            longest = (longest.size() < str.size()) ? str : longest;
        }
    }
    cout << longest << endl;
}