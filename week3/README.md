# 第三周作业：第四讲、第五讲编程练习

| 项目 | 内容 |
| --- | --- |
| 姓名 | 王蕾睿 |
| 学号 | 2026302192069 |
| 学院 / 班级 | 武汉大学 人工智能学院 2603 班 |
| 课程 | 高级语言程序设计（C++ 语言） |
| 实验环境 | Windows 11 + VS Code + MinGW-w64 g++ 16.1.0（C++17） |

本周作业分两部分：`src/part4` 是第四讲的 6 道题（类与对象、构造析构、位域、重载），
`src/part5` 是第五讲的 3 道题（作用域、静态成员、友元）。所有程序都经过实际编译运行。

## 目录

| 讲次 | 题号 | 内容 | 源码 |
| --- | --- | --- | --- |
| 4 | 4-10 | 人员类（Date 内嵌，类的组合） | [src/part4/01_person.cpp](src/part4/01_person.cpp) |
| 4 | 4-13 | Circle 类求面积 | [src/part4/02_circle.cpp](src/part4/02_circle.cpp) |
| 4 | 4-19 | CPU 类（位域） | [src/part4/03_cpu.cpp](src/part4/03_cpu.cpp) |
| 4 | 4-20 | Complex 类（转换构造） | [src/part4/04_complex.cpp](src/part4/04_complex.cpp) |
| 4 | 4-12 | DataType 类（构造函数重载） | [src/part4/05_datatype.cpp](src/part4/05_datatype.cpp) |
| 4 | 4-14 | Tree 类（树龄累加） | [src/part4/06_tree.cpp](src/part4/06_tree.cpp) |
| 5 | 5-3 | 全局/局部作用域 | [src/part5/01_scope.cpp](src/part5/01_scope.cpp) |
| 5 | 5-7 | Cat 类（静态数据成员与静态函数） | [src/part5/02_cat/](src/part5/02_cat/) |
| 5 | 5-13 | X/Y/Z 类（友元函数与友元类） | [src/part5/03_friend/](src/part5/03_friend/) |

## 编译与运行

单文件的题直接编译：

```bash
g++ -std=c++17 -O2 src/part4/01_person.cpp -o person
./person
```

多文件的题要把同目录下的 `.cpp` 一起编译：

```bash
g++ -std=c++17 -O2 src/part5/02_cat/main.cpp src/part5/02_cat/Cat.cpp -o cat
./cat

g++ -std=c++17 -O2 src/part5/03_friend/main.cpp -o friend
./friend
```

---

## 第四讲

### 4-10 人员类（类的组合）

用 `Date` 类表示出生日期，`Person` 里内嵌一个 `Date` 对象；实现了构造函数、析构函数、复制构造函数、
内联成员函数、带默认形参值的成员函数。

输入 `1001 男 2005 3 15 420106200503150011` 的运行结果：

```text
编号    ：1001
性别    ：男
出生日期：2005-3-15
身份证号：420106200503150011
```

复制构造出的副本与它完全一致，最后按 `p3 → p2 → p1` 逆序析构。

### 4-13 Circle 类

```text
请输入圆的半径：5
半径 = 5
面积 = 78.5398
```

### 4-19 CPU 类（位域）

```text
时钟频率：3000 MHz
字长    ：64 位
核数    ：四核
超线程  ：支持
sizeof(CPU) = 2 字节
```

字段位宽：频率 12 位（0～4095，够放 3000）+ 字长 1 位 + 核数 2 位 + 超线程 1 位 = 16 位 = 2 字节。

### 4-20 Complex 类

```cpp
Complex c1(3, 5);     // 3+5i
Complex c2 = 4.5;     // 用实数 4.5 初始化，靠转换构造函数
c1.add(c2);
c1.show();
```

```text
7.5+5i
```

### 4-12 DataType 类（构造函数重载）

```text
数据类型：char   值：'A'
数据类型：int    值：65
数据类型：double 值：3.14
```

三个构造函数按参数类型区分，编译器做重载决议：精确匹配优先，`3.14f` 会提升为 `double`。

### 4-14 Tree 类

```text
树龄：5 年
树龄：8 年
树龄：18 年
```

## 第五讲

### 5-3 全局变量与局部变量

```text
x from main5
y from main7
x from myFunction5
y from myFunction10

Back from myFunction!

x from main5
y from main7
```

`myFunction` 里的 `int y = 10` 是局部变量，函数返回后 `main` 看到的 `y` 仍是全局的 7；
`x` 是全局变量，两处访问的是同一个。

### 5-7 Cat 类（静态成员）

```text
程序开始时，猫的数量：0
创建 a 之后：1
块内创建 b、c 之后：3
拷贝构造 d 之后：4
离开块之后：1
```

静态数据成员 `numOfCats` 属于类，必须在类外定义一次；静态成员函数没有 `this`，可用类名直接调用。

### 5-13 X / Y / Z（友元）

```text
初始 i = 0
Y::g 把 i 加 1 后，i = 1
Z::f 把 i 加 5 后，i = 6
h   把 i 加 10 后，i = 16
```

`Y::g` 是成员函数作友元，`Z` 是友元类，`h` 是普通函数作友元；声明顺序要求先完整定义 `Y`。
