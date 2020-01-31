/*
 * @Author: liyunfang
 * @Date: 2020-01-29 22:48:24
 * @LastEditTime : 2020-01-30 17:29:30
 * @Description: 
 */
#ifndef EX13_5_8_11_22H
#define EX13_5_8_11_22H

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
            auto tp = new string(*rhs.ps);
            delete ps;
            ps = tp;
            i = rhs.i;
        }
        return *this;
    }
    ~HasPtr() { delete ps; }

private:
    string *ps;
    int i;
};

#endif