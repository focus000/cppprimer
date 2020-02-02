<!--
 * @Author: liyunfang
 * @Date: 2020-01-29 22:21:01
 * @LastEditTime : 2020-01-30 20:38:33
 * @Description: 
 -->
# 第13章

## 练习 13.1

A copy constructor is a constructor which first parameter is a reference to the class type and any additional parameters have default values.

When copy initialization happens and that copy initialization requires either the copy constructor or the move constructor.

- Define variables using an =
- Pass an object as an argument to a parameter of nonreference type
- Return an object from a function that has a nonreference return type
- Brace initialize the elements in an array or the members of an aggregate class
- Some class types also use copy initialization for the objects they allocate.

## 练习 13.2

将一个对象作为实参传给一个非引用类型的形参时会进行拷贝初始化，所以一个拷贝构造函数里面是个非引用类型的形参时就会无限循环调用。

## 练习 13.3

when we copy a StrBlob, the shared_ptr member's use_count add one.

when we copy a StrBlobPrts, the weak_ptr member's use_count isn't changed.(cause the count belongs to shared_ptr)

## 练习 13.4

```cpp
Point global;
Point foo_bar(Point arg) // 1
{
    Point local = arg, *heap = new Point(global); // 2, 3
    *heap = local; //copy assignment
    Point pa[ 4 ] = { local, *heap }; // 4, 5
    return *heap; // 6
}
```

## 练习 13.6

The copy-assignment operator is function named operator= and takes an argument of the same type as the class.

This operator is used when assignment occurred.

The synthesized copy-assignment operator assigns each nonstatic member of the right-hand object to corresponding member of the left-hand object using the copy-assignment operator for the type of that member.

It is synthesized when the class does not define its own.

## 练习 13.7

In both cases, shallow copy will happen. All pointers point to the same address. The use_count changed the same as 13.3.

## 练习 13.9

The destructor is a member function with the name of the class prefixed by a tilde(~).

As with the copy constructor and the copy-assignment operator, for some classes, the synthesized destructor is defined to disallow objects of the type from being destoryed. Otherwise, the synthesized destructor has an empty function body.

The compiler defines a synthesized destructor for any class that does not define its own destructor.

## 练习 13.10

When a StrBlob object destroyed, the use_count of the dynamic object will decrement. It will be freed if no shared_ptr to that dynamic object.

When a StrBlobPter object is destroyed the object dynamically allocated will not be freed.

## 练习 13.12

3 times. There are accum, item1 and item2.

## 练习 13.14

三个相同的序号

## 练习 13.15

三个不同的序号，但是不与`a.mysn``b.mysn``c.mysn`保持一致

## 练习 13.16

三个不同的序号，但是与`a.mysn``b.mysn``c.mysn`保持一致

## 练习 13.20

The member (smart pointer and container) will be copied.

## 练习 13.21

As synthesized version meet all requirements for this case, no custom version control memebers need to define

## 练习 13.24

If HasPtr didn't define a destructor, a memory leak would occur, compiler synthesized destructor does not manage dynamic memory. If HasPtr didn't define the copy constructor, we would get pointer-like copy behaviour. The ps pointer would be copied to the left hand side, but ps in the lhs and the rhs would still point to the same string on the heap.

## 练习 13.25

Copy constructor and copy-assignment operator should dynamically allocate memory for its own , rather than share the object with the right hand operand.

StrBlob is using smart pointers which can be managed with synthesized destructor, If an object of StrBlob is out of scope, the destructor for std::shared_ptr will be called automatically to free the memory dynamically allocated when the use_count goes to 0.

## [练习 13.26](ch12/ex12_02.h)

## 练习 13.29

`swap(lhs.ps, rhs.ps)`; feed the version : `swap(std::string*, std::string*)` and `swap(lhs.i, rhs.i)`; feed the version : `swap(int, int)`. Both them can't call `swap(HasPtr&, HasPtr&)`. Thus, the calls don't cause a recursion loop.

## 练习 13.32

Essentially, the specific avoiding memory allocation is the reason why it improve performance. As for the pointerlike version, no dynamic memory allocation anyway. Thus, a specific version for it will not improve the performance.

## 练习 13.33

Because these operations must also update the given Folder. Updating a Folder is a job that the Folder class controls through its addMsg and remMsg members, which will add or remove a pointer to a given Message, respectively.

## [练习 13.34](Message.h)

## 练习 13.35

相关`Folder`对象没法同步更新。

## [练习 13.36](Message.h)

## [练习 13.37](Message.h)

## 练习 13.38

@Mooophy The copy and swap is an elegant way when working with dynamicly allocated memory. In the Message class , nothing is allocated dynamically. Thus using this idiom makes no sense and will make it more complicated to implement due to the pointers that point back.

@pezy In this case, swap function is special. It will be clear two Message's folders , then swap members, and added themselves to each folders. But, Message assignment operator just clear itself, and copy the members, and added itself to each folders. The rhs don't need to clear and add to folders. So, if using copy and swap to define, it will be very inefficiency.

## [练习 13.39](StrVec.h)

## [练习 13.40](StrVec.h)

## 练习 13.41

```
|a|b|c|d|f|..............|
^	       ^             ^
elements   first_free    cap

// if use alloc.construct(first_free++, "g");
|a|b|c|d|f|g|.............|
^	         ^            ^
elements     first_free   cap

// if use alloc.construct(++first_free, "g");
|a|b|c|d|f|.|g|............|
^	       ^ ^             ^
elements   | first_free    cap
	       |
    "unconstructed"
```

## [练习 13.43](StrVec.cpp)

## 练习 13.45

- 右值引用绑定右值，左值引用绑定左值
- 右值短暂，左值持久

## 练习 13.46

```cpp
int f();
vector<int> vi(100);
int&& r1 = f();
int& r2 = vi[0];
int& r3 = r1;
int&& r4 = vi[0] * f();
```

## [练习 13.47](String.cpp)

## 练习 13.50

```cpp
String baz()
{
    String ret("world");
    return ret; // first avoided
}

String s5 = baz(); // second avoided
```

## 练习 13.51

For such case, move semantics is expected rather than copy operation.That's why a unique_ptr may be returned from a function by value. Reference: [StackOverflow - returning unique pointers from functions](http://stackoverflow.com/questions/4316727)

## 练习 13.52

传入左值，调用拷贝构造函数，传入右值，精确匹配移动构造函数

## 练习 13.53

所以为啥时间差10倍啊？重载的更快

## 练习 13.54

```
error: ambiguous overload for 'operator=' (operand types are 'HasPtr' and 'std::remove_reference<HasPtr&>::type { aka HasPtr }')
hp1 = std::move(*pH);
^
```

## [练习 13.55](../ch12/ex12_02.h)
