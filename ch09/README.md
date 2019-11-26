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