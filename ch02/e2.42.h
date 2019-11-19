//
// Created by 李蕴方 on 2019-02-26.
//

#ifndef C_PRIMER_E2_42_H
#define C_PRIMER_E2_42_H

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    void CalcRevenue(double price);

    double CalcAveragePrice();

    void SetData(Sales_data data);

    void AddData(Sales_data data);

    void Print();
};

void Sales_data::CalcRevenue(double price) {
    revenue = units_sold * price;
}

double Sales_data::CalcAveragePrice() {
    if (units_sold != 0) {
        return revenue / units_sold;
    } else {
        return 0.0;
    }
}

void Sales_data::SetData(Sales_data data) {
    bookNo = data.bookNo;
    units_sold = data.units_sold;
    revenue = data.revenue;
}

void Sales_data::AddData(Sales_data data) {
    if (bookNo != data.bookNo) return;
    units_sold += data.units_sold;
    revenue += data.revenue;
}

void Sales_data::Print() {
    std::cout << bookNo << " " << units_sold << " " << revenue << " ";
    double averagePrice = CalcAveragePrice();
    if (averagePrice != 0.0) {
        std::cout << averagePrice << std::endl;
    } else {
        std::cout << "no sales" << std::endl;
    }
}

#endif //C_PRIMER_E2_42_H
