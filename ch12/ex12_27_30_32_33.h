/*
 * @Author: liyunfang
 * @Date: 2020-01-29 17:09:05
 * @LastEditTime : 2020-01-29 21:05:17
 * @Description: 
 */
#ifndef EX12_27_30_32_33H
#define EX12_27_30_32_33H

#include <map>
#include <set>
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
#include <string>
using std::string;
#include <fstream>
#include <iostream>
#include "ex12_19.h"

class QueryResult;

class TextQuery
{
public:
    using LineNo = StrBlob::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(string const &) const;

private:
    shared_ptr<StrBlob> input;
    std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult
{
public:
    friend std::ostream &print(std::ostream &, QueryResult const &);
    using ResultIter = std::set<StrBlob::size_type>::iterator;
    QueryResult(string const &s, shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<StrBlob> v) : word(s), nos(set), input(v) {}
    ResultIter begin() const { return nos->begin(); }
    ResultIter end() const { return nos->end(); }
    auto get_file() const { return input; }

private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<StrBlob> input;
};

std::ostream &print(std::ostream &, QueryResult const &);

#endif