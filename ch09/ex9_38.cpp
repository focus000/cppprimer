#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v;
    int const counter = 0xF00;
    while (v.size() <= counter)
    {
        int prev = v.capacity();
        v.push_back(1);
        if (prev != v.capacity())
        {
            cout << v.size() << " " << v.capacity() << endl;
        }
    }
    
}