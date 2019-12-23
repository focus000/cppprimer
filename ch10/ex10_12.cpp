#include "../ch07/ex7_41.h"
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

inline bool
compareIsbn(Sales_data const &sd1, Sales_data const &sd2)
{
    return sd1.isbn().size() < sd2.isbn().size();
}

int main()
{
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    vector<Sales_data> vsd{d1, d2, d3, d4, d5};
    sort(vsd.begin(), vsd.end(), compareIsbn);
    for (auto &&i : vsd)
    {
        cout << i.isbn() << " ";
    }
    cout << endl;
}