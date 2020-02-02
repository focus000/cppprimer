#include "String.h"
#include <algorithm>
#include <iostream>

void swap(String &lhs, String &rhs)
{
    lhs.swap(rhs);
}

std::pair<char *, char *>
String::alloc_n_copy(char const *first, char const *last)
{
    auto data = alloc.allocate(last - first);
    return {data, std::uninitialized_copy(first, last, data)};
}

void String::range_initializer(char const *first, char const *last)
{
    auto data = alloc_n_copy(first, last);
    elements = data.first;
    end_ = data.second;
}

void String::free()
{
    std::for_each(elements, end_, [this](char &c){ alloc.destroy(&c); });
    alloc.deallocate(elements, size());
}

String::String(char const *c_str)
{
    char *sl = const_cast<char *>(c_str);
    while (*sl)
    {
        ++sl;
    }
    range_initializer(c_str, sl);
}

String::String(String const &rhs)
{
    range_initializer(rhs.begin(), rhs.end());
    std::cout << "copy constructor" << std::endl;
}

String &String::operator=(String tmp)
{
    swap(tmp);
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

String::String(String &&rhs) noexcept
: elements(rhs.elements), end_(rhs.end_)
{
    rhs.elements = rhs.end_ = nullptr;
}

String::~String()
{
    free();
}
