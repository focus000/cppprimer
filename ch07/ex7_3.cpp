#include <iostream>
#include "ex7_2.h"

int main()
{
    Sales_data total;
    if (std::cin >> total.bookNo >> total.revenue >> total.units_sold)
    {
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.revenue >> trans.units_sold)
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                std::cout << total.bookNo << " "
                          << total.revenue << " "
                          << total.units_sold << std::endl;
                total = trans;
            }
        }
        std::cout << total.bookNo << " "
                  << total.revenue << " "
                  << total.units_sold << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}