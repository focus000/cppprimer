# 第9章

## 练习 9.1

(a) `list` ，因为需要频繁的插入操作。

(b) `deque` ，总是在头尾进行插入、删除操作。

(c) `vector` ，不需要进行插入删除操作。

## 练习 9.2

```cpp
std::list<std::deque<int>> obj;
```

## 练习 9.3

- 它们指向同一个容器中的元素，或者是容器最后一个元素之后的位置。
- 我们可以通过反复递增 begin 来到达 end。换句话说，end 不在 begin 之前。

## [练习 9.4](ch09/ex9_4.cpp)

## [练习 9.5](ch09/ex9_5.cpp)

## 练习 9.6

`list`不支持比较大小的运算

## 练习 9.7

```cpp
std::vector<int>::size_type
```

## 练习 9.8

```cpp
std::list<string>::const_iterator
std::list<string>::iterator
```

## 练习 9.9

`begin`返回普通迭代器，`cbegin`返回常量迭代器

## 练习 9.10

题目写法有误，应改为：

```cpp
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```

其中

```cpp
it1: vector<int>::iterator
oters: vector<int>::const_iterator
```

## 练习 9.11

```cpp
vector<int> vi; // vi is empty
vector<int> vi(10); //0
vector<int> vi(10, 1);  //1
vector<int> vi{1, 2, 3};    //1, 2, 3
vector<int> vi(other_vec);  //same as other_vec
vector<int> vi(iter1, iter2);   //elements in [iter1, iter2)
```

## 练习 9.12

- The constructor that takes another container as an argument (excepting array) assumes the container type and element type of both containers are identical. It will also copy all the elements of the received container into the new one:

```cpp
list<int> numbers = { 1, 2, 3, 4, 5 };
list<int> numbers2(numbers);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers);      // error: no matching function for call...
list<double> numbers4(numbers);     // error: no matching function for call...
```

- The constructor that takes two iterators as arguments does not require the container types to be identical. Moreover, the element types in the new and original containers can differ as long as it is possible to convert the elements we’re copying to the element type of the container we are initializing.
It will also copy only the object delimited by the received iterators.

```cpp
list<int> numbers = { 1, 2, 3, 4, 5 };
list<int> numbers2(numbers.begin(), numbers.end);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers.begin(), --numbers.end());  // ok, numbers3 is { 1, 2, 3, 4 }
list<double> numbers4(++numbers.beg(), --numbers.end());        // ok, numbers4 is { 2, 3, 4 }
forward_list<float> numbers5(numbers.begin(), numbers.end());   // ok, number5 is { 1, 2, 3, 4, 5 }
```

## [练习 9.13](ch09/ex9_13.cpp)

## [练习 9.14](ch09/ex9_14.cpp)

## [练习 9.15](ch09/ex9_15.cpp)

## [练习 9.16](ch09/ex9_16.cpp)

## 练习 9.17

- 必须不是无序关联容器
- 容器以及元素类型必须一致
- 容器元素类型必须定义了关系运算符

## [练习 9.18](ch09/ex9_18.cpp)

## [练习 9.19](ch09/ex9_19.cpp)

## [练习 9.20](ch09/ex9_20.cpp)

## 练习 9.21

> 第一次调用 insert 会将我们刚刚读入的 string 插入到 iter 所指向的元素之前的位置。insert 返回的迭代器恰好指向这个新元素。我们将此迭代器赋予 iter 并重复循环，读取下一个单词。只要继续有单词读入，每步 while 循环就会将一个新元素插入到 iter 之前，并将 iter 改变为新加入元素的尾置。此元素为（新的）首元素。因此，每步循环将一个元素插入到 list 首元素之前的位置。

## 练习 9.22

- 死循环
- 迭代器失效

fixed:

```cpp
while (iter != mid)
{
    if (*iter == some_val)
    {
        iter = v.insert(iter, 2 * some_val);
        ++iter;
    }
    ++iter;
}
```

## 练习 9.23

`val == val2 == val3 == val4`

## [练习 9.24](ch09/ex9_24.cpp)

## 练习 9.25

相等不删除元素，返回迭代器位置

## [练习 9.26](ch09/ex9_26.cpp)

## [练习 9.27](ch09/ex9_27.cpp)

## [练习 9.28](ch09/ex9_28.cpp)

## 练习 9.29

`vec.resize(100)` 增加75个元素进行值初始化
`vec.resize(10)` 删除后90个元素

## 练习 9.30

不能是没有默认构造函数的类类型

## [练习 9.31](ch09/ex9_31.cpp)

## 练习 9.32

不合法，因为不能确定表达式求值顺序

## [练习 9.33](ch09/ex9_33.cpp)

`segmentation fault` 迭代器未定义

## [练习 9.34](ch09/ex9_34.cpp)

死循环

## 练习 9.35

`capacity` 总空间
`size` 已用空间

## 练习 9.36

不可能

## 练习 9.37

`list`不是连续存储，`array`大小固定

## [练习 9.38](ch09/ex9_38.cpp)

## 练习 9.39

分配至少能容纳1024个元素的内存空间，向`svec`填充元素，再增加一半元素。

## 练习 9.40

for clang: 1024 1024 2048 2048
