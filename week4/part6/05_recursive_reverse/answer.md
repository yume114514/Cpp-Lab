# 6-22 用递归函数使字符串倒序

## 题目

编写函数 `void reverse(string &s)`，用递归函数使字符串 `s` 倒序。

本题实现见 [main.cpp](main.cpp)。

## 一、思路：交换首尾 + 缩小范围

递归地做同一件事：

1. 交换当前范围的首字符和尾字符；
2. 把范围往里缩一格（左下标 +1，右下标 −1）；
3. 直到左右下标相遇（`i >= j`）为止。

以 `abcd` 为例：

| 步骤 | 当前串 | 动作 |
| --- | --- | --- |
| 1 | `abcd` | 交换 `i=0` 的 `a` 与 `j=3` 的 `d` → `dbca` |
| 2 | `dbca` | 交换 `i=1` 的 `b` 与 `j=2` 的 `c` → `dcba` |
| 3 | `dcba` | 此时 `i=2, j=1`，`i >= j`，递归结束 |

## 二、代码结构

题目签名只给了 `void reverse(string &s)` 一个参数，而交换首尾需要知道「从哪到哪」，
所以用两个函数：

- `reversefrom(s, i, j)`：真正干活的递归函数，带左右下标；
- `reverse(s)`：题目要求的签名，只负责把 `0` 和 `size()-1` 传进去。

```cpp
void reversefrom(string &arr, int i, int j){
    if (i >= j) return;
    char t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
    reversefrom(arr, i + 1, j - 1);
}

void reverse(string &arr){
    reversefrom(arr, 0, (int)arr.size() - 1);
}
```

## 三、两个易错点

### 1. `(int)` 强制转换不能省

`arr.size()` 的返回类型是 `size_t`（无符号整数）。空串时 `arr.size() - 1` 会发生**无符号下溢**，
变成 `18446744073709551615` 这样的巨大值，而不是 `-1`。强转成 `int` 之后才会得到真正的 `-1`，
`i >= j` 才能正常成立、递归才会立刻结束。

### 2. 出口条件用 `i >= j`，不是 `i == j`

长度为偶数时（如 `abcd`），交换到最后会出现 `i > j`（`i=2, j=1`）的情况，
只写 `i == j` 会漏掉这种情况，导致越界访问。

## 四、运行结果

编译：`g++ -std=c++17 -O2 -Wall main.cpp -o rev`，0 错误 0 警告。

| 输入 | 输出 |
| --- | --- |
| `sfhhsdfjfh` | `hfjfdshhfs` |
| `hello world` | `dlrow olleh` |
| `a` | `a` |
| 空串 | 空串 |

## 五、另一种写法（不借助下标）

不写辅助函数、只用 `void reverse(string &s)` 一个参数也可以：

```cpp
void reverse(string &s){
    if (s.size() <= 1) return;
    char first = s[0];
    s.erase(0, 1);
    reverse(s);
    s.push_back(first);
}
```

原理：把首字符摘下来 → 递归倒序剩下的 → 把摘下来的字符补到末尾。
摘的顺序是 `a→b→c`，补的顺序是 `c→b→a`，所以拼出 `dcba`。

以 `abcd` 实测的每一步：

```text
进入, s = [abcd], size = 4
  first = 'a', erase(0,1) 后 s = [bcd]
  进入, s = [bcd], size = 3
    first = 'b', erase(0,1) 后 s = [cd]
    进入, s = [cd], size = 2
      first = 'c', erase(0,1) 后 s = [d]
      进入, s = [d], size = 1
        -> 出口, 直接返回
      push_back('c') 后 s = [dc]
    push_back('b') 后 s = [dcb]
  push_back('a') 后 s = [dcba]
结果: [dcba]
```

两种写法都可以提交，本题采用的是「交换首尾」这一版。

## 六、为什么不能直接调库

`std::reverse(s.begin(), s.end())` 一行就能完成倒序，但题目要求自己用递归实现，
调库就失去了这道题的训练意义，不能作为答案。
