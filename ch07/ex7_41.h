#ifndef CP5_EX7_41_H
#define CP5_EX7_41_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;

class Sales_data
{
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);

public:
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { cout << "Sales_data(const std::string &, unsigned, double)" <<endl; }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) { cout << "Sales_data(const std::string &)" << endl; }
    Sales_data(): Sales_data("", 0, 0.0) { cout << "Sales_data()" << endl; }
    Sales_data(std::istream &is): Sales_data() { cout << "Sales_data(std::istream &)" << endl; read(is, *this); }

    std::string isbn() const{ return bookNo; }
    Sales_data &combine(const Sales_data &rhs);

private:
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline
double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);


#endif