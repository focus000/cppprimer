<!--
 * @Author: liyunfang
 * @Date: 2019-12-14 14:11:42
 * @LastEditTime : 2019-12-24 00:04:19
 * @Description: 
 -->
# 第10章

## [练习 10.1 & 10.2](ch10/ex10_1&2.cpp)

## [练习 10.3](ch10/ex10_3.cpp)

## 练习 10.4

会把所有浮点数相加然后返回整型，详见标准库实现。

## 练习 10.5

比较指向C风格字符串指针的地址

## [练习 10.6](ch10/ex10_6.cpp)

## 练习 10.7

(a) the vec.begin() was replaced by a back_inserter iterator, capable of insert new elements automatically at the end of the container.
(b) No error, but not any sense. v.size() still equal zero.
    // Fixed: 1. use `v.resize(10);`
    //    or  2. use `fill_n(std::back_inserter(v), 10, 0)`

## 练习 10.8

Inserters like back_inserter is part of \<iterator\> rather than \<algorithm\>.

## [练习 10.9](ch10/ex10_9.cpp)

## 练习 10.10

容器大小是容器本身的属性。改变大小是容器本身的实现细节，不应该由外部探针（iterator）来管理。比如shared_ptr，其内部的对象计数器也不应该由使用者来管理一样。面向对象设计原则。

## [练习 10.11](ch10/ex10_11.cpp)

## [练习 10.12](ch10/ex10_12.cpp)

## [练习 10.13](ch10/ex10_13.cpp)

## 练习 10.14

```cpp
[] (int num1, int num2) { return num1 + num2; }
```

## 练习 10.15

```cpp
[num1] (int num2) {return num1 + num2}
```

## [练习 10.16](ch10/ex10_16.cpp)

## [练习 10.17](ch10/ex10_17.cpp)

## [练习 10.18](ch10/ex10_18.cpp)

## [练习 10.19](ch10/ex10_19.cpp)

## [练习 10.20](ch10/ex10_20.cpp)

## [练习 10.21](ch10/ex10_21.cpp)

## [练习 10.22](ch10/ex10_22.cpp)

## 练习 10.23

Assuming the function to be bound have n parameters, bind take n + 1 parameters. The additional one is for the function to be bound itself.

## [练习 10.24](ch10/ex10_24.cpp)

## [练习 10.25](ch10/ex10_25.cpp)
