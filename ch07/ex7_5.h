#ifndef CP5_EX7_5_H
#define CP5_EX7_5_H

#include <string>

struct Person
{
    // std::string const &get_name() const { return name; }
    // std::string const &get_address() const { return address; }
    auto get_name() const -> std::string const & { return name; }
    auto get_address() const -> std::string const & { return address; }

    std::string name, address;
};

#endif