#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

auto sum_for_int(vector<string> const &v)
{
    int sum = 0;
    for (auto &&i : v)
    {
        sum += stoi(i);
    }
    return sum;
}

auto sum_for_float(vector<string> const &v)
{
    float sum = 0;
    for (auto &&i : v)
    {
        sum += stof(i);
    }
    return sum;
}

int main()
{
    vector<string> v{"1", "3", "6.4", "7.9"};
    cout << sum_for_int(v) << " " << sum_for_float(v) << endl;
}