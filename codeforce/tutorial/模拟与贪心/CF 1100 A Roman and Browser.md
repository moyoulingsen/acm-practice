# CF 1100 A - Roman and Browser

**题目链接**：<https://codeforces.com/problemset/problem/1100/A>

**题型**：模拟

---

## 题意压缩

关闭同一个模 `k` 余数类的标签，枚举关闭哪一类，最大化剩余和绝对值。

---

## 关键观察

关闭同一个模 `k` 余数类的标签，枚举关闭哪一类，最大化剩余和绝对值。

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

int main(){int n,k;cin>>n>>k;vector<int>a(n);int sum=0;for(int&i:a)cin>>i,sum+=i;int ans=0;for(int st=0;st<k;st++){int rem=0;for(int i=st;i<n;i+=k)rem+=a[i];ans=max(ans,abs(sum-rem));}cout<<ans<<'\n';}

```

---

## 一句话总结

关闭同一个模 `k` 余数类的标签，枚举关闭哪一类，最大化剩余和绝对值。
