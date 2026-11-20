# 6-21 统计英文句子中字母的个数

## 题目

编写一个函数，统计一条英文句子中字母的个数，在主程序中实现输入输出。

本题实现见 [main.cpp](main.cpp)。

## 一、思路

1. 主程序用 `getline(cin, s)` 读**一整行**（`cin >> s` 遇空格就停，读不到整句）；
2. 函数从头到尾扫一遍，是字母就 `cnt++`；
3. 判断字母用范围比较：`(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')`，
   也可以用 `isalpha(ch)`（需 `#include <cctype>`）；
4. 返回 `cnt`，主程序输出。

## 二、代码

```cpp
#include <iostream>
#include <string>
using namespace std;

int countLetters(const string &s){
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        char ch = s[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) cnt++;
    }
    return cnt;
}

int main(){
    string s;
    getline(cin, s);
    cout << countLetters(s) << endl;
    return 0;
}
```

形参写成 `const string &s`：引用避免拷贝整句，`const` 表示函数内不修改它。

## 三、运行结果

编译：`g++ -std=c++17 -O2 -Wall main.cpp -o count`，0 错误 0 警告。

| 输入 | 输出 | 说明 |
| --- | --- | --- |
| `Hello World` | 10 | 空格不算 |
| `Hello, World! 123` | 10 | 逗号、感叹号、数字都不算 |
| `abc` | 3 | |
| `   ` | 0 | 全是空格 |
| `中文测试` | 0 | 中文的字节都 > 127，不在 `a~z`/`A~Z` 范围内 |

## 四、要点

- `getline` 才能读到带空格的整句；
- 循环条件里的 `(int)s.size()` 强转：`size()` 返回 `size_t`，和 `int i` 比较时会有符号/无符号混合比较的警告；
- 题目说的是「英文字母」，所以中文、数字、标点、空格一律不算。
