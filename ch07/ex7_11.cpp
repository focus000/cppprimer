#include <iostream>
#include "ex7_11.h"

int main()
{
    Sales_data item1, item2("asshole"), item3("blowjob", 3, 12.4), item4(std::cin);
    print(std::cout, item1) << std::endl;
    print(std::cout, item2) << std::endl;
    print(std::cout, item3) << std::endl;
    print(std::cout, item4) << std::endl;
}