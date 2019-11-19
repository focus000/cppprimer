#include <iostream>
#include <vector>

using std::vector;

void print(std::vector<int>::const_iterator first, std::vector<int>::const_iterator end)
{
    if (first != end)
    {
        std::cout << *first << std::endl;
        print(++first, end);
    }
}

int main()
{
    vector<int> ivec{1, 4, 6, 2, 3, 0, -3};
    print(ivec.cbegin(), ivec.cend());
    return 0;
}