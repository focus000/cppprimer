/*
 * @Author: liyunfang
 * @Date: 2020-01-29 22:48:24
 * @LastEditTime : 2020-01-30 17:29:30
 * @Description: 
 */
#ifndef EX13_5_8_11_22_30_31H
#define EX13_5_8_11_22_30_31H

#include <iostream>
#include <string>
using std::string;

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(HasPtr const &, HasPtr const &);
public:
    HasPtr(string const &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(HasPtr const &hp) : ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(HasPtr rhs)
    {
        this->swap(rhs);
        return *this;
    }
    ~HasPtr() { delete ps; }
    void swap(HasPtr &rhs)
    {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(" << *rhs.ps << ")" << std::endl;
    }

private:
    string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    lhs.swap(rhs);
}
bool operator<(HasPtr const &lhs, HasPtr const &rhs)
{
    return (*lhs.ps == *rhs.ps) ? (lhs.i < rhs.i) : (*lhs.ps < *rhs.ps);
}

#endif