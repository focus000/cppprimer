#ifndef CP5_EX7_27_H
#define CP5_EX7_27_H

#include <string>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(const pos &ht, const pos &wd) : height(ht), width(wd) {}
    Screen(const pos &ht, const pos &wd, const char &c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    char get(const pos &r, const pos &c) const;
    Screen &move(const pos &r, const pos &c);
    Screen &set(const char ch);
    Screen &set(const pos r, const pos c, const char ch);
    Screen &display(std::ostream &os);
    const Screen &display(std::ostream &os) const;

private:
    void do_display(std::ostream &os) const { os << contents; }

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

inline Screen &Screen::set(const char ch)
{
    contents[cursor] = ch;
    return *this;
}
inline Screen &Screen::set(const pos r, const pos c, const char ch)
{
    contents[r * width + c] = ch;
    return *this;
}
inline Screen &Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
}
inline const Screen &Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}

#endif