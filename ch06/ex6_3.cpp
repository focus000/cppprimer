#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int fact(int val)
{
    if (val < 0)
    {
        runtime_error err("Input cannot be negative number");
        // cout << err.what() << endl;
        throw err;
    }
    return val > 1 ? val * fact(val - 1) : 1;
}

int main()
{
    cout << std::boolalpha << (1 == fact(-5)) << endl;
    return 0;
}