#ifndef CP5_CH14_EX14_02_H
#define CP5_CH14_EX14_02_H

#include <string>
#include <iostream>

class Sales_data
{
    friend std::istream &operator>>(std::istream &, Sales_data &);
    friend std::ostream &operator<<(std::ostream &, Sales_data const &);
    friend Sales_data operator+(Sales_data const &, Sales_data const &);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    inline double avg_price() const;

public:
    Sales_data(std::string const &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p) {}
    Sales_data() : bookNo("") {}
    Sales_data(std::string const &s) : bookNo(s) {}
    Sales_data(std::istream &);

    Sales_data &operator+=(Sales_data const &);
    std::string isbn() const { return bookNo; }

    ~Sales_data() {}
};

std::istream &operator>>(std::istream &, Sales_data &);
std::ostream &operator<<(std::ostream &, Sales_data const &);
Sales_data operator+(Sales_data const &, Sales_data const &);

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

#endif