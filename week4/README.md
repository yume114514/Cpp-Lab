# 第四周作业：第六讲编程练习（数组、指针与字符串）

| 项目 | 内容 |
| --- | --- |
| 姓名 | 王蕾睿 |
| 学号 | 2026302192069 |
| 学院 / 班级 | 武汉大学 人工智能学院 2603 班 |
| 课程 | 高级语言程序设计（C++ 语言） |
| 实验环境 | Windows 11 + VS Code + MinGW-w64 g++ 16.1.0（C++17） |

本周只有第六讲一个部分，5 道编程练习（6-17、6-18、6-20、6-21、6-22），
一题一个子文件夹，源码与答案分析都放在各自文件夹里。

## 目录

```
week4/
└─ part6/
   ├─ 01_pointer_uninit/      6-17  野指针：未初始化就解引用
   ├─ 02_memory_leak/         6-18  内存泄漏：new 了不 delete
   ├─ 03_simple_circle/       6-20  SimpleCircle 类（int *itsRadius）
   ├─ 04_count_letters/       6-21  统计英文句子中的字母个数
   └─ 05_recursive_reverse/   6-22  递归实现 void reverse(string &s)
```

## 题目与状态

| 编号 | 题号 | 内容 | 类型 | 状态 | 位置 |
| --- | --- | --- | --- | --- | --- |
| 01 | 6-17 | 指针未初始化就解引用 | 找错 + 分析 | ✅ 已分析 | [part6/01_pointer_uninit/](part6/01_pointer_uninit/) |
| 02 | 6-18 | `new` 之后没有 `delete` | 找错 + 改正 | ✅ 已分析 | [part6/02_memory_leak/](part6/02_memory_leak/) |
| 03 | 6-20 | `SimpleCircle` 类，`int *itsRadius` | 编程 | ✅ 已完成 | [part6/03_simple_circle/](part6/03_simple_circle/) |
| 04 | 6-21 | 统计英文句子中字母的个数 | 编程 | ✅ 已完成 | [part6/04_count_letters/](part6/04_count_letters/) |
| 05 | 6-22 | 递归函数 `void reverse(string &s)` | 编程 | ✅ 已完成 | [part6/05_recursive_reverse/](part6/05_recursive_reverse/) |

## 编译与运行

```bash
g++ -std=c++17 -O2 -Wall part6/01_pointer_uninit/main.cpp -o t
./t
```

## 找错题的答案怎么写（6-17、6-18 这类题）

不要写成「第几行有错」的散文，按下面四段固定结构写，每段一句话到三句话：

1. **现象**：程序实际表现是什么（能编译吗、能运行吗、输出什么、退出码多少）。
2. **根因**：用一句术语点明（野指针 / 内存泄漏），并指出出错的那一行。
3. **机制**：为什么编译器不管（类型合法，最多 warning），以及为什么运行时会出现这个结果（未定义行为，结果依赖环境）。
4. **避免方法**：给出正确写法的一句话要求（指针定义即初始化、`new`/`delete` 配对）。

两条硬规矩：**每条结论都要能对应到源码某一行**；**「碰巧对」不等于是对的**，
未定义行为的结果不能作为正确性的依据。

---

## 6-17 指针未初始化就解引用

题目原程序见 [part6/01_pointer_uninit/main.cpp](part6/01_pointer_uninit/main.cpp)，
完整答案与分析见 [part6/01_pointer_uninit/answer.md](part6/01_pointer_uninit/answer.md)。

要点：

- `int *p;` 只分配了「存放地址」的变量，`p` 里是栈上的随机值（野指针）。
- `*p=9;` 把 9 写到 `p` 里那个随机地址上，属于未定义行为。
- 编译能过是因为类型合法：`p` 是 `int*`、`*p` 是 `int`，赋 9 没有问题；`-Wall` 只给出
  `'p' is used uninitialized` 的 **warning**，不是 error。
- 同一份源码换优化等级结果就不同：`-O0` 打印 `the value at p:9`，`-O2` 直接崩（退出码 `0xC0000005` 访问冲突）。
- 避免：`int x; int *p = &x;`，或 `new`，或先置 `nullptr` 再判断。

## 6-18 `new` 之后没有 `delete`（内存泄漏）

题目原程序 [part6/02_memory_leak/original.cpp](part6/02_memory_leak/original.cpp)，
改正版 [part6/02_memory_leak/main.cpp](part6/02_memory_leak/main.cpp)，
完整答案与分析见 [part6/02_memory_leak/answer.md](part6/02_memory_leak/answer.md)。

要点：

- `fn1` 里 `new int(5)` 申请了堆内存却没 `delete`，返回的只是 `*p` 的**值的拷贝**；
- 局部指针 `p` 随函数返回销毁，堆上那块内存的地址彻底丢失，再也无法释放 → 内存泄漏；
- 输出 `the value of a is:5` 是正确的，所以错误不体现在结果上，编译器也完全不给警告；
- 实测（各循环 500 万次）：无 `delete` 峰值 76.3 MB，有 `delete` 峰值 4.2 MB，两者输出都是 `25000000`；
- 改正：先 `int value = *p;`，再 `delete p;`，最后 `return value;`（顺序不能反，
  `delete` 之后不能再解引用）；或者根本不用 `new`，直接 `int x = 5; return x;`。

## 6-20 SimpleCircle 类（指针做数据成员）

源码 [part6/03_simple_circle/main.cpp](part6/03_simple_circle/main.cpp)，
完整说明见 [part6/03_simple_circle/answer.md](part6/03_simple_circle/answer.md)。

要点：

- 半径不在对象里，而在 `itsRadius` 指向的堆内存里 → **构造 `new`、析构 `delete` 必须配对**；
- 取/改操作的是 `*itsRadius` 这块内存，`setradius` 里不要再 `new`；
- 运行结果：输入 `1.5` → `radius is: 1.5`、`area is 7.06858`；输入 `8` → `area is 201.062`；
- 踩过的坑：`Class` 写成大写（关键字必须小写）、`int*` 与 `double*` 不能互赋、
  `main` 里 `int r` 会把输入 `1.5` 截成 `1`（`cin` 按整数解析，遇到小数点就停）、
  `pow` 需要 `#include <cmath>`；
- 遗留隐患：没写拷贝构造，若拷贝对象会两个对象共用一块内存、析构两次崩溃（本题 `main` 没拷贝，未触发）。

## 6-22 递归实现 `void reverse(string &s)`

源码 [part6/05_recursive_reverse/main.cpp](part6/05_recursive_reverse/main.cpp)，
完整说明见 [part6/05_recursive_reverse/answer.md](part6/05_recursive_reverse/answer.md)。

要点：

- 思路：交换首尾字符 → 左右下标各缩一格 → 相遇（`i >= j`）时结束；
- 题目签名只有 `s` 一个参数，所以用带下标的辅助函数 `reversefrom(s, i, j)`，`reverse(s)` 负责传 `0` 和 `size()-1`；
- `(int)arr.size() - 1` 的强转不能省：`size()` 返回无符号数，空串时 `size()-1` 会下溢成一个巨大的正数；
- 出口写 `i >= j` 而不是 `i == j`：偶数长度时最后会出现 `i > j`；
- 实测：`sfhhsdfjfh → hfjfdshhfs`、`hello world → dlrow olleh`、`a → a`、空串 → 空串；
- 另一种不用下标的写法（`char first = s[0]; s.erase(0,1); reverse(s); s.push_back(first);`）记在 `answer.md` 里。

## 6-21 统计英文句子中字母的个数

源码 [part6/04_count_letters/main.cpp](part6/04_count_letters/main.cpp)，
完整说明见 [part6/04_count_letters/answer.md](part6/04_count_letters/answer.md)。

要点：

- `getline(cin, s)` 读整句，`cin >> s` 遇空格就停；
- 循环逐字符判断，`(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')` 才计数；
- 实测：`Hello World → 10`、`Hello, World! 123 → 10`、`abc → 3`、全空格 → `0`、中文 → `0`；
- `04_count_letters/size_test.cpp` 是最早那个 `sizeof` / `size()` 对比小实验，留作记录。
