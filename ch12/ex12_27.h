/*
 * @Author: liyunfang
 * @Date: 2020-01-29 17:09:05
 * @LastEditTime : 2020-01-29 19:20:19
 * @Description: 
 */
#ifndef EX12_27H
#define EX12_27H

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

class QueryResult;

class TextQuery
{
public:
    using LineNo = std::vector<string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(string const &) const;

private:
    shared_ptr<vector<string>> input;
    std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult
{
public:
    friend std::ostream &print(std::ostream &, QueryResult const &);
    QueryResult(string const &s, shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v) : word(s), nos(set), input(v) {}

private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

std::ostream &print(std::ostream &, QueryResult const &);

#endif