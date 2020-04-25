#include "ch14/Book.h"

std::istream &operator>>(std::istream &is, Book &item)
{
    if (is)
    {
        is >> item.isbn_ >> item.name_ >> item.author_ >> item.pubdate_;
    }
    else
    {
        item = Book();
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, Book const &item)
{
    os << item.isbn_ << " "
       << item.name_ << " "
       << item.author_ << " "
       << item.pubdate_ << " ";
    return os;
}

bool operator==(Book const &lhs, Book const &rhs)
{
    if (lhs.isbn_ == rhs.isbn_ && lhs.name_ == rhs.name_ && lhs.author_ == rhs.author_ && lhs.pubdate_ == rhs.pubdate_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(Book const &lhs, Book const &rhs)
{
    return !(lhs == rhs);
}