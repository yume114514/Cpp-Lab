# 6-18 内存泄漏

## 题目

下列程序有何问题，请改正；仔细体会使用指针时应避免出现的这个问题。

```cpp
#include<iostream>
using namespace std;
int fn1(){
    int *p=new int(5);
    return *p;
}
int main(){
    int a=fn1();
    cout<<"the value of a is:"<<a;
    return 0;
}
```

## 要求

1. 指出问题所在（`new` 与 `delete` 是否配对）；
2. 给出改正后的完整程序，并说明为什么结果仍然正确、但问题已经消除；
3. 说清楚「值能正确传回来」和「内存没还回去」是两件互不影响的事。

## 状态

⏳ 待写源码（`main.cpp`）与答案（`answer.md`）。
