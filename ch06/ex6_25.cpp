#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string str;
    for (size_t i = 1; i != argc; ++i)
    {
        str += std::string(argv[i]) + " ";
    }
    std::cout << str << std::endl;
    return 0;
}