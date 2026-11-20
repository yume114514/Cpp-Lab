# 6-20 SimpleCircle 类（`int *itsRadius` 指向半径）

## 题目

实现一个名为 `SimpleCircle` 的简单圆类。其数据成员 `int *itsRadius` 为一个指向其半径值的
指针，存放其半径值。设计对数据成员的各种操作，给出这个类的完整实现并测试这个类。

本题实现见 [main.cpp](main.cpp)。

## 一、设计思路

数据成员是一个**指针**，所以半径不在对象里，而在它指向的堆内存里。由此得到三条必然结论：

1. 构造函数里必须 `new` 一块内存，让 `itsRadius` 指向它；
2. 析构函数里必须 `delete`，否则就是 6-18 那道题的内存泄漏；
3. 对数据成员的操作（取/改）操作的是 `*itsRadius` 这块内存，不是指针本身。

类的成员：

| 成员 | 作用 |
| --- | --- |
| `double *itsRadius`（private） | 指向半径值，值本身存放在堆上 |
| `SimpleCircle(double radius)` | 构造：`itsRadius = new double(radius);` |
| `~SimpleCircle()` | 析构：`delete itsRadius;` |
| `void setradius(double r)` | `*itsRadius = r;`，改值不重新 `new` |
| `double getradius() const` | `return *itsRadius;` |
| `double getarea() const` | `pow(*itsRadius, 2) * 3.1415926` |

本题的实现把半径存成 `double`（题目原意是 `int *`，用 `double` 可以处理小数半径，
与 `double getradius()` 的返回类型一致）。

## 二、运行结果

```text
please input the radious: radius is: 1.5
area is 7.06858
```

```text
please input the radious: radius is: 8
area is 201.062
```

编译：`g++ -std=c++17 -O2 -Wall main.cpp -o circle`，0 错误 0 警告。

## 三、踩过的坑

### 1. `class` 不能写成 `Class`

C++ 关键字全部小写，`Class` 不是关键字，编译器会当成未知类型名，然后整个类体解析全乱，
后面 `private:`、`public:`、`};` 全部跟着报错。

### 2. 指针类型必须一致

成员是 `int *itsRadius` 时，`itsRadius = new double(r);` 会报
`cannot convert 'double*' to 'int*'`。指针类型决定解引用时读几个字节、怎么解释，
不同类型的指针不能互相赋值。**成员、形参、`new` 三处类型必须一致。**

### 3. 输入变量类型要和成员一致

`double *itsRadius` + `SimpleCircle(double radius)` 配套，但 `main` 里写成 `int r;`
就会出现：输入 `1.5`，`cin >> r` 按整数解析，只读走 `1`，小数点被丢在缓冲区，
于是半径变成 1、面积变成 3.14159（π×1×1）。

改成 `double r;` 后：

| `main` 里的写法 | 输入 | `radius is:` | `area is` |
| --- | --- | --- | --- |
| `int r;` | 1.5 | `1` | `3.14159` |
| `double r;` | 1.5 | `1.5` | `7.06858` |

### 4. `pow` 需要 `<cmath>`

`pow` 不在 `<iostream>` 里，缺 `#include <cmath>` 时报
`'pow' was not declared in this scope`。半径平方也可以直接写 `*itsRadius * *itsRadius`，
就不必包含 `<cmath>`。

## 四、遗留隐患（本题未要求，但要知道）

这个类只实现了构造/析构/取/改/面积，**没有写拷贝构造函数**。如果这样写：

```cpp
SimpleCircle c(5);
SimpleCircle d = c;      // 默认拷贝构造：只把指针拷过去
```

`d.itsRadius` 和 `c.itsRadius` 会指向**同一块内存**。程序结束时两个对象各析构一次，
同一块内存被 `delete` 两次，程序崩溃（double free）。

正确做法是写深拷贝：

```cpp
SimpleCircle::SimpleCircle(const SimpleCircle &other){
    itsRadius = new double(*other.itsRadius);
}
```

本题 `main` 里没有拷贝对象，所以不写也不会出错；但如果以后要在数组、返回值、函数传参里
使用这个类，就必须补上。
