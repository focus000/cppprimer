#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int abs(int num)
{
    return num > 0 ? num : - num;
}

int main()
{
    cout << abs(0) << endl;
    return 0;
}