/*
 * @Author: liyunfang
 * @Date: 2020-01-27 15:14:25
 * @LastEditTime : 2020-01-29 01:41:35
 * @Description: 
 */
#ifndef EX12_02H
#define EX12_02H

#include <vector>
#include <string>
#include <memory>
#include <exception>

using std::vector, std::string;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob(): data(std::make_shared<vector<string>>()) { }
    StrBlob(std::initializer_list<string> il): data(std::make_shared<vector<string>>(il)) { }
    StrBlob(StrBlob const &sb): data(std::make_shared<vector<string>>(*sb.data)) { }
    StrBlob &operator=(StrBlob const &rhs)
    {
        data = std::make_shared<vector<string>>(*rhs.data);
        return *this;
    }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(string const &t) { data->push_back(t); }
    void pop_back()
    {
        check(0, "pop back on empty StrBlob");
        data->pop_back();
    }
    string &front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string &back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const string &front() const
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const string &back() const
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const
    {
        if (i >= data->size()) throw std::out_of_range(msg);
    }
};
#endif