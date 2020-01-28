/*
 * @Author: liyunfang
 * @Date: 2020-01-29 00:10:00
 * @LastEditTime : 2020-01-29 01:08:40
 * @Description: 
 */
#include "ex12_02.h"
#include "ex12_19.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::ifstream ifs("data/book.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str);)
    {
        blob.push_back(str);
    }
    for (auto iter = blob.begin(); iter != blob.end(); iter.incr())
    {
        std::cout << iter.deref() << " ";
    }
    std::cout << std::endl;
}