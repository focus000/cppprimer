#include <iostream>
#include <vector>

using std::vector;

int sum(int lhs, int rhs)
{
    return lhs + rhs;
}

int mins(int lhs, int rhs)
{
    return lhs - rhs;
}

int mul(int lhs, int rhs)
{
    return lhs * rhs;
}

int frac(int lhs, int rhs)
{
    return (rhs == 0) ? 0 : (lhs / rhs);
}

vector<decltype(sum) *> ptrfun{sum, mins, mul, frac};

int main()
{
    for (auto f : ptrfun)
    {
        std::cout << f(9, 3) << std::endl;
    }
    return 0;
}