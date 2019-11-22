#ifndef CP5_EX7_23_H
#define CP5_EX7_23_H

#include <string>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(const pos &ht, const pos &wd, const char &c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    char get(const pos &r, const pos &c) const;
    Screen &move(const pos &r, const pos &c);

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline char Screen::get(const pos &r, const pos &c) const
{
    return contents[r * width + c];
}

inline Screen &Screen::move(const pos &r, const pos &c)
{
    cursor = r * width + c;
    return *this;
}

#endif