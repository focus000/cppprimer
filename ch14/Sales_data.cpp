#include "Sales_data.h"
#include <exception>

Sales_data::Sales_data(std::istream &is) : Sales_data()
{
    is >> *this;
}

Sales_data& Sales_data::operator+=(Sales_data const &rhs)
{
    *this = *this + rhs;
    return *this;
}

std::istream &operator>>(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
    {
        item.revenue = item.units_sold * price;
    }
    else
    {
        item = Sales_data();
        // return_key means clear?
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, Sales_data const &item)
{
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(Sales_data const &lhs, Sales_data const &rhs)
{
    if (lhs.bookNo != rhs.bookNo)
    {
        throw std::runtime_error("different isbn can not add");
    }
    else
    {
        return Sales_data(lhs.bookNo, lhs.units_sold + rhs.units_sold, lhs.revenue + rhs.revenue);
    }
}