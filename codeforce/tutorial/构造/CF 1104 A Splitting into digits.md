# CF 1104 A - Splitting into digits

**题目链接**：<https://codeforces.com/problemset/problem/1104/A>

**题型**：构造

---

## 题意压缩

只用数字 1 就能表示任意 `n`，不同数字种类数最少为 1。

---

## 关键观察

只用数字 1 就能表示任意 `n`，不同数字种类数最少为 1。

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

int main(){int n;cin>>n;cout<<n<<'\n';for(int i=0;i<n;i++)cout<<1<<' ';cout<<'\n';}

```

---

## 一句话总结

只用数字 1 就能表示任意 `n`，不同数字种类数最少为 1。
