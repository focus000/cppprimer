#include <iostream>
#include <string>

std::istream &func(std::istream &is)
{
    std::string buf;
    while (is >> buf)
    {
        std::cout << buf << std::endl;
    }
    is.clear();
    return is;
}

int main()
{
    std::cout << func(std::cin).rdstate() << std::endl;
    return 0;
}