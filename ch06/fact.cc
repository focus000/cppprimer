#include "Chapter6.h"

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::range_error;

int fact(int val)
{
    return val > 1 ? val * fact(val - 1) : 1;
}

void interactive_fact()
{
    cout << "Enter a number within [1, 13)" << "\n";
    int num;
    cin >> num;
    try
    {
        if (!cin || num < 1 || num > 12)
        {
            throw range_error("Out of range");
        }
        cout << fact(num) << endl;
        
    }
    catch(range_error e)
    {
        std::cerr << e.what() << '\n';
        cout << "Try again? Enter y or press any key to terminate the application" << endl;
        char c;
        cin >> c;
        if (cin && c == 'y')
        {
            interactive_fact();
        }
        else
        {
            throw;
        }
        
    }
    
}

int myabs(int num)
{
    return num > 0 ? num : - num;
}