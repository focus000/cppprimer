/*
 * @Author: liyunfang
 * @Date: 2020-01-29 22:48:24
 * @LastEditTime : 2020-01-29 23:31:41
 * @Description: 
 */
#ifndef EX13_5_8H
#define EX13_5_8H

#include <string>
using std::string;

class HasPtr
{
public:
    HasPtr(string const &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(HasPtr const &hp) : ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(HasPtr const &rhs)
    {
        if (this != &rhs)
        {
            delete ps;
            ps = new string(*rhs.ps);
            i = rhs.i;
        }
        return *this;
    }

private:
    string *ps;
    int i;
};

#endif