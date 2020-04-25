#ifndef CP5_CH14_EX14_05_H
#define CP5_CH14_EX14_05_H

#include <iostream>
#include <string>

class Book
{
    friend std::istream &operator>>(std::istream &, Book &);
    friend std::ostream &operator<<(std::ostream &, Book const &);
    friend bool operator==(Book const &, Book const &);
    friend bool operator!=(Book const &, Book const &);

public:
    Book() = default;
    Book(unsigned isbn, std::string const &name, std::string const &author, std::string const &pubdate)
        : isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    {
    }

    explicit Book(std::istream &in) //explicit关键字用来修饰类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换，只能以显示的方式进行类型转换。
    {
        in >> isbn_ >> name_ >> author_ >> pubdate_;
    }

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};

std::istream &operator>>(std::istream &, Book &);
std::ostream &operator<<(std::ostream &, Book const &);
bool operator==(Book const &, Book const &);
bool operator!=(Book const &, Book const &);

#endif