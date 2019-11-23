#ifndef CP5_EX7_43_H
#define CP5_EX7_43_H

class Nodefault
{
public:
    Nodefault(int i) {}
};

class C
{
public:
    C() : t(1) {}

private:
    Nodefault t;
};

#endif