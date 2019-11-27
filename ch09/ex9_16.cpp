#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::list;
using std::vector;

inline bool isEqual(const list<int> &ilst, const vector<int> &ivec)
{
    return vector<int>(ilst.begin(), ilst.end()) == ivec;
}

int main()
{
    list<int> il(20);
    vector<int> iv1(20);
    vector<int> iv2(10, 3);
    cout << std::boolalpha << isEqual(il, iv1) << endl;
    cout << std::boolalpha << isEqual(il, iv2) << endl;
}