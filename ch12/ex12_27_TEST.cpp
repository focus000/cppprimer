/*
 * @Author: liyunfang
 * @Date: 2020-01-29 19:51:00
 * @LastEditTime: 2020-01-29 19:51:34
 * @Description: 
 */
#include "ex12_27.h"
#include <iostream>

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main()
{
    std::ifstream file("data/storyDataFile.txt");
    runQueries(file);
}