/*
 * @Author: liyunfang
 * @Date: 2020-01-29 22:48:24
 * @LastEditTime : 2020-01-29 22:56:24
 * @Description: 
 */
#ifndef EX13_5H
#define EX13_5H

#include <string>
using std::string;

class HasPtr
{
public:
    HasPtr(string const &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(HasPtr const &hp) : ps(new string(*hp.ps)), i(hp.i) {}

private:
    string *ps;
    int i;
};

#endif