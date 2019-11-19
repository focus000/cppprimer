//
// Created by 李蕴方 on 2019-02-23.
//

#include <iostream>

int main() {
    int i = 10, j, *p1 = &i, *p2 = &j;
    p1 = p2;
    *p2 = i;
    std::cout << *p1 << " " << *p2 << std::endl;

    return 0;
}