<!--
 * @Author: liyunfang
 * @Date: 2020-01-29 22:21:01
 * @LastEditTime : 2020-01-29 23:20:05
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
