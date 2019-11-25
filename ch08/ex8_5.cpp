#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ifstream;

void ReadFileToVec(const string &fileName, vector<string> &vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
        {
            vec.push_back(buf);
        }
    }
    else
    {
        std::cerr << "couldn't open" + string(fileName);
    }
}