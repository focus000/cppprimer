#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

inline bool isEqual(const vector<int> &ivec1, const vector<int> &ivec2)
{
    return ivec1 == ivec2;
}

int main()
{
    vector<int> iv1(20);
    vector<int> iv2(10, 3);
    cout << std::boolalpha << isEqual(iv1, iv2) << endl;
}