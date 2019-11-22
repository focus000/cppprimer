#ifndef CP5_EX7_31_H
#define CP5_EX7_31_H

class Y;

class X
{
    Y *ptr = nullptr;
};

class Y
{
    X obj;
};

#endif