#ifndef CP5_EX7_9_H
#define CP5_EX7_9_H

#include <string>
#include <iostream>

struct Person
{
    auto get_name() const -> std::string const & { return name; }
    auto get_address() const -> std::string const & { return address; }
    
    std::string name, address;
};

std::istream &read(std::istream &is, Person item)
{
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person item)
{
    os << item.name << " " << item.address;
    return os;
}

#endif