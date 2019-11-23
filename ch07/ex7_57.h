#ifndef CP5_EX7_57_H
#define CP5_EX7_57_H

#include <string>

class Account
{
    public:
    void calculate() { amount += amount * interestRate; }
    static double rate();
    static void rate( double newRate );

    private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate();
};

constexpr double Account::todayRate;
double Account::initRate() { return todayRate; }
double Account::interestRate = initRate();

double Account::rate() { return interestRate; }
void Account::rate( double newRate ) { interestRate = newRate; }

#endif