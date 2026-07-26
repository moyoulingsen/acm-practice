# CF 1088 A - Ehab and another construction problem

**题目链接**：<https://codeforces.com/problemset/problem/1088/A>

**题型**：构造

---

## 题意压缩

`x=1` 无解；否则取 `a=b=x`，满足乘积大于 `x` 且商小于 `x`。

---

## 关键观察

`x=1` 无解；否则取 `a=b=x`，满足乘积大于 `x` 且商小于 `x`。

---

## 思路步骤

直接按关键观察实现即可。

---

## 复杂度

见代码，均满足题目限制。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){int x;cin>>x;if(x==1)cout<<-1<<'\n';else cout<<x<<' '<<x<<'\n';}

```

---

## 一句话总结

`x=1` 无解；否则取 `a=b=x`，满足乘积大于 `x` 且商小于 `x`。
