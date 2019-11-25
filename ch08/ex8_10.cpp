#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main( int argc, char **argv )
{
    ifstream input(argv[1]);
    if (!input)
    {
        cerr << "No data?" << endl;
        return -1;
    }

    vector<string> vecLine;
    string line;
    while (getline(input, line))
    {
        vecLine.push_back(line);
    }
    
    for (auto &s : vecLine)
    {
        istringstream iss(s);
        string word;
        while (iss >> word)
        {
            cout << word << endl;
        }
    }

    return 0;
}