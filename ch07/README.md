# 第7章 练习

## [练习 7.1](ch07/ex7_1.cpp)

## [练习 7.2](ch07/ex7_2.h)

## [练习 7.3](ch07/ex7_3.cpp)

## [练习 7.4](ch07/ex7_4.h)

## [练习 7.5](ch07/ex7_5.h)

应该是`const`，需要兼容常量`Person`对象。

## [练习 7.6](ch07/ex7_6.h)

## [练习 7.7](ch07/ex7_7.cpp)

## 练习 7.8

因为我们需要在`read()`函数运行时给`Sales_data`参数赋值，`print()`函数不需要

## [练习 7.9](ch07/ex7_9.h)

## 练习 7.10

一次读入两个对象。

## [练习 7.11](ch07/ex7_11.cpp)

## [练习 7.12](ch07/ex7_12.h)

## [练习 7.13](ch07/ex7_13.cpp)

## 练习 7.14

```cpp
Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
```

## [练习 7.15](ch07/ex7_15.h)

## 练习 7.16

没限定，类用户使用的成员放`public`后，不希望用户使用的放`private`后

## 练习 7.17

`class` 默认访问权限`private`，`struct`默认`public`

## 练习 7.18

将类内部分成员设置为外部不可见，而提供部分接口给外面，这样的行为叫做封装。封装隐藏了具体的实现，当我们使用某个抽象数据类型时，只需要考虑它提供什么接口操作，而不用去考虑它的具体实现。

## 练习 7.19

`public`: 构造函数，`get_name`, `get_address`
`private`: `name`, `address`
数是暴露给外部的接口，因此要设为public；而数据则应该隐藏让外部不可见。

## 练习 7.20

友元声明让其他类或者函数可以访问类的`private`部分，但是牺牲了封装性与可维护性，并且代码啰嗦

## [练习 7.21](ch07/ex7_21.h)

## [练习 7.22](ch07/ex7_22.h)

## [练习 7.23](ch07/ex7_23.h)

## [练习 7.24](ch07/ex7_24.h)

## 练习 7.25

能。`Screen`的成员只有内置类型和`string`，因此能安全地依赖于拷贝和赋值操作的默认版本。管理动态内存的类则不能依赖于拷贝和赋值操作的默认版本，而且也应该尽量使用`string`和`vector`来避免动态管理内存的复杂性。

## 练习 7.26（[.h](ch07/ex7_26.h)|[.cpp](ch07/ex7_26.cpp)）

## 练习 7.27（[.h](ch07/ex7_27.h) | [.cpp](ch07/ex7_27.cpp)）

## 练习 7.28 & 7.29

```sh
#with '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
                   ^^^
# without '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
                   ^^^
```

## 练习 7.30

**优点**：

* 程序的意图更明确
* 函数的参数可以与成员同名，如

```cpp
void setAddr(const std::string &addr) { this->addr = addr; }
```

**缺点**：

* 有时候显得有点多余，如

```cpp
std::string getAddr() const { return this->addr; }
```

## [练习 7.31](ch07/ex7_31.h)

## [练习 7.32](ch07/ex7_32.h)

## 练习 7.33

```cpp
Screen::pos Screen::size() const
{
    return height * width;
}
```

## 练习 7.34

```sh
dummy_fcn(pos height)
           ^
Unknown type name 'pos'
```

## 练习 7.35

```cpp
typedef string Type;
Type initVal(); //use `string`
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);  //use `double`
    Type initVal(); //use `double`
private:
    int val;
};
Type Exercise::setVal(Type parm) {  //first `string`, second `double`
    val = parm + initVal(); //Exercise::initVal()
    return val;
}
```

change to

```cpp
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

## 练习 7.36

fixed

```cpp
struct X {
  X (int i, int j): base(i), rem(i % j) { }
  int base, rem;
};
```

## 练习 7.37

```cpp
Sales_data first_item(cin);   // use Sales_data(std::istream &is) ; its value are up to your input.

int main() {
  Sales_data next;  // use Sales_data(std::string s = ""); bookNo = "", cnt = 0, revenue = 0.0
  Sales_data last("9-999-99999-9"); // use Sales_data(std::string s = ""); bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
```

## 练习 7.38

```cpp
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

## 练习 7.39

不合法，调用`Sales_data()`会产生二义性调用

## 练习 7.40

```cpp
#include <iostream>
#include <string>

class Book 
{
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    { }

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
```

## 练习 7.41([header](ch07/ex7_41.h)|[cpp](ch07/ex7_41.cpp)|[test](ch07/ex7_41_TEST.cpp))

## 练习 7.42

参考 练习 7.40
