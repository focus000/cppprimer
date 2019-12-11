#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vi;
    std::cout
        << vi.at(0) << "\n"      // terminating with uncaught exception of type std::out_of_range: vector
        << vi[0] << "\n"         // segmentation fault
        << vi.front() << "\n"    // segmentation fault
        << *vi.begin()           // segmentation fault
        << std::endl;
}