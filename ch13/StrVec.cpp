#include "StrVec.h"
#include <algorithm>

std::allocator<std::string> StrVec::alloc;

void StrVec::free()
{
    if (elements)
    {
        std::for_each(elements, first_free, [this](std::string &rhs){ alloc.destroy(&rhs); });
        alloc.deallocate(elements, capacity());
    }
}

void StrVec::alloc_n_move(size_type new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_type i = 0; i != size(); ++i) alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::reallocate()
{
    auto new_cap = size() ? size() * 2 : 1;
    alloc_n_move(new_cap);
}

auto StrVec::alloc_n_copy(std::string const *b, std::string const *e) -> std::pair<std::string *, std::string *>
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::range_initialize(std::string const  *first, std::string const *last)
{
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec const &rhs)
{
    range_initialize(rhs.begin(), rhs.end());
}

StrVec::StrVec(std::initializer_list<std::string> li)
{
    range_initialize(li.begin(), li.end());
}

StrVec &StrVec::operator=(StrVec const &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

StrVec::StrVec(StrVec &&rhs) noexcept
: elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap;
    }
    return *this;
}

StrVec::~StrVec() { free(); }

void StrVec::reserve(size_type new_cap)
{
    if (new_cap > capacity())
    {
        alloc_n_move(new_cap);
    }
}

void StrVec::resize(size_type count, std::string const &s)
{
    if (count > size())
    {
        if (count > capacity()) reserve(count * 2);
        for (auto i = size(); i != count; ++i) alloc.construct(first_free++, s);
    }
    else if (count < size())
    {
        for (auto i = size(); i != count; --i) alloc.destroy(--first_free);
    }
}

void StrVec::resize(size_type count)
{
    resize(count, std::string());
}

void StrVec::push_back(std::string const &str)
{
    chk_n_alloc();
    alloc.construct(first_free++, str);
}
