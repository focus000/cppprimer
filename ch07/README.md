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

## [练习 7.43](ch07/ex7_43.h)

## 练习 7.44

不合法，因为没有默认构造函数。

## 练习 7.45

合法，因为 C 有默认构造函数。

## 练习 7.46

全错

## 练习 7.47

是否需要从 string 到 Sales_data 的转换依赖于我们对用户使用该转换的看法。在此例中，这种转换可能是对的。null_book 中的 string 可能表示了一个不存在的 ISBN 编号。

优点：

可以抑制构造函数定义的隐式转换
缺点：

为了转换要显式地使用构造函数

## 练习 7.48

这些定义和是不是 explicit 的无关。

## 练习 7.49

```cpp
(a) Sales_data &combine(Sales_data); // ok
(b) Sales_data &combine(Sales_data&); // error C2664: 无法将参数 1 从“std::string”转换为“Sales_data &”	
(c) Sales_data &combine(const Sales_data&) const; // 该成员函数是const 的，意味着不能改变对象。而 combine函数的本意就是要改变对象
```

关于(b)，错误的主要原因是non-const ref不能用临时变量过度，事实上声明成`Sales_data &combine(const Sales_data&);`是完全可以的

## [练习 7.50](ch07/ex7_50.h)

## 练习 7.51

假如我们有一个这样的函数：

```cpp
int getSize(const std::vector<int>&);
```

如果vector没有将单参数构造函数定义成 explicit 的，我们就可以这样调用：

```cpp
getSize(34);
```

很明显这样调用会让人困惑，函数实际上会初始化一个拥有34个元素的vector的临时量，然后返回34。但是这样没有任何意义。而 string 则不同，string 的单参数构造函数的参数是 `const char *` ，因此凡是在需要用到 string 的地方都可以用 `const char *` 来代替（字面值就是 `const char *`）。如：

```cpp
void print(std::string);
print("hello world");
```

## 练习 7.52

Sales_data 类不是聚合类，应该修改成如下：

```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

## [练习 7.53](ch07/ex7_53.h)

## 练习 7.54

in C++11, constexpr member functions are implicitly const, so the "set_xx" functions, which will modify data members, cannot be declared as constexpr. In C++14, this property no longer holds, so constexpr is suitable.

## 练习 7.55

不是，因为`std::string`不是字面值常量
我们可以用以下代码做检测：

```cpp
#include <string>
#include <iostream>
#include <type_traits>

struct Data {
    int ival;
    std::string s;
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<Data>::value << std::endl;
    // output: false
}
```

## 练习 7.56

A class member that is **associated with the class**, rather than with individual objects of the class type.

each object can no need to store a common data. And if the data is changed, each object can use the new value.

a static data member can have incomplete type.
we can use a static member as a default argument.

## [练习 7.57](ch07/ex7_57.h)

## 练习 7.58

```cpp
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```
