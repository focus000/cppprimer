#include "../ch07/ex7_41.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);

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
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}