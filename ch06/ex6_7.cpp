#include <iostream>

using std::cout;
using std::endl;
using std::size_t;

size_t add()
{
    static size_t sum = 0;
    return sum++;
}

int main()
{
    for (int count = 0; count != 5; ++count)
    {
        cout << add() << "\n";
    }
    cout << endl;
    return 0;
}