#include <iostream>
using namespace std;

int test(const int &i)
{
    return i;
}

int main()
{
    cout << test(12) << endl;
    return 0;
}