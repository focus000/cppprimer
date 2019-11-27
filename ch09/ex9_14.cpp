#include <list>
#include <vector>
#include <string>

using std::list;
using std::vector;
using std::string;

int main()
{
    list<char *> cpli;
    vector<string> strvec;
    strvec.assign(cpli.begin(), cpli.end());
}