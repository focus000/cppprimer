#ifndef EX13_18_19H
#define EX13_18_19H

#include <string>

class Employee
{
private:
    std::string name;
    int id;
    static int unique;
public:
    Employee() : name("unknown"), id(unique++) {}
    Employee(std::string const &str) : name(str), id(unique++) {}
    Employee(Employee const &) = delete;
    Employee &operator=(Employee const &) = delete;
    ~Employee() { --unique; }
};

int Employee::unique = 0;

#endif