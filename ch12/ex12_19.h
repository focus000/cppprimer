/*
 * @Author: liyunfang
 * @Date: 2020-01-28 23:05:33
 * @LastEditTime : 2020-01-29 00:29:23
 * @Description: 
 */
#ifndef EX12_19H
#define EX12_19H

#include <vector>
#include <string>
#include <exception>
#include "ex12_02.h"

using std::vector, std::string;

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    auto &deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    auto &incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    std::weak_ptr<vector<string>> wptr;
    std::size_t curr;

private:
    auto check(std::size_t i, std::string const &msg) const -> std::shared_ptr<vector<string>>
    {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
};
#endif