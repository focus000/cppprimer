/*
 * @Author: liyunfang
 * @Date: 2020-01-29 18:44:54
 * @LastEditTime : 2020-01-29 20:21:35
 * @Description: 
 */
#include "ex12_27.h"
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs)
{
    input = std::make_shared<vector<string>>();
    LineNo lineNo{0};
    for (string line; std::getline(ifs, line); ++lineNo)
    {
        input->push_back(line);
        std::istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear())
        {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            auto &nos = result[word];
            if (!nos)
                nos.reset(new std::set<LineNo>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(string const &str) const
{
    static auto nodata = std::make_shared<std::set<LineNo>>();
    auto found = result.find(str);
    if (found == result.end())
        return QueryResult(str, nodata, input);
    return QueryResult(str, found->second, input);
}

std::ostream &print(std::ostream &out, const QueryResult &qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i + 1 << ") " << qr.input->at(i) << std::endl;
    return out;
}