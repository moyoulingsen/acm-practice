# CF 1088 B - Ehab and subtraction

**题目链接**：<https://codeforces.com/problemset/problem/1088/B>

**题型**：排序 / 模拟

---

## 题意压缩

排序后只输出每个新的不同值与之前累计减去值的差，剩余次数输出 0。

---

## 关键观察

排序后只输出每个新的不同值与之前累计减去值的差，剩余次数输出 0。

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

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k;cin>>n>>k;vector<long long>a(n);for(auto&x:a)cin>>x;sort(a.begin(),a.end());long long last=0;int out=0;for(long long x:a)if(out<k&&x>last){cout<<x-last<<'\n';last=x;out++;}while(out<k)cout<<0<<'\n',out++;}

```

---

## 一句话总结

排序后只输出每个新的不同值与之前累计减去值的差，剩余次数输出 0。
