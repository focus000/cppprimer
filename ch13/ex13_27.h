#ifndef EX13_27H
#define EX13_27H

#include <string>
using std::string;

class HasPtr
{
public:
    HasPtr(string const &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(HasPtr const &hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
    HasPtr &operator=(HasPtr const &rhs)
    {
        ++*rhs.use;
        if (--*use)
        {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    ~HasPtr()
    {
        if (--*use)
        {
            delete ps;
            delete use;
        }
    }

private:
    string *ps;
    int i;
    size_t *use;
};

#endif