#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

auto bracket_match(string const &str)
{
    stack<char> stk;
    for (auto const &c : str)
    {
        if (c != ')')
        {
            stk.push(c);
        }
        else
        {
            string repstr;
            while (!stk.empty() && stk.top() != '(')
            {
                repstr.insert(0, string{stk.top()});
                stk.pop();
            }
            if (stk.empty())
            {
                throw std::runtime_error("there is extra ')'!");
            }
            else if (stk.top() == '(')
            {
                stk.pop();
                for (auto const &c : repstr)
                {
                    stk.push(c);
                }
            }
        }
    }
    
    string repstr;
    while (!stk.empty() && stk.top() != '(')
    {
        repstr.insert(0, string{stk.top()});
        stk.pop();
    }
    if (!stk.empty() && stk.top() == '(')
    {
        throw std::runtime_error("extra '('!");
    }

    return repstr;
}

int main()
{
    cout << bracket_match("asdas(wertre((drgre0)sdf)sdfe(ferte((erte))))") << endl;
}