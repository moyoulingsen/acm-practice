# CF 1085 B - Div Times Mod

**题目链接**：<https://codeforces.com/problemset/problem/1085/B>

**题型**：数学 / 枚举因子

---

## 题意压缩

设 `q=x/k, r=x%k`，则 `q*r=n` 且 `1<=r<k`，枚举余数 `r`。

---

## 关键观察

设 `q=x/k, r=x%k`，则 `q*r=n` 且 `1<=r<k`，枚举余数 `r`。

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

int main(){long long n,k;cin>>n>>k;long long ans=4e18;for(long long r=1;r<k;r++)if(n%r==0)ans=min(ans,n/r*k+r);cout<<ans<<'\n';}

```

---

## 一句话总结

设 `q=x/k, r=x%k`，则 `q*r=n` 且 `1<=r<k`，枚举余数 `r`。
