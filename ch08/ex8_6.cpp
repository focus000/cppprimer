#include "../ch07/ex7_41.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);

    Sales_data total(input);
    if (input)
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}