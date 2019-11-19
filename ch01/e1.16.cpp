//
// Created by 李蕴方 on 2019-02-19.
//

#include <iostream>

int main() {
    int sum = 0, i = 0;
    std::cout << "input: " << std::endl;
    while (std::cin >> i) {
        sum += i;
    }
    std::cout << "the sum is: " << sum <<std::endl;
    return 0;
}