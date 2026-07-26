# CF 1085 A - Right-Left Cipher

**题目链接**：<https://codeforces.com/problemset/problem/1085/A>

**题型**：字符串 / 构造

---

## 题意压缩

加密串按左右交替生成，解密时按奇偶位置逆序取回。

---

## 关键观察

加密串按左右交替生成，解密时按奇偶位置逆序取回。

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

int main(){string t;cin>>t;int n=t.size();string ans;for(int i=(n%2?n-1:n-2);i>=0;i-=2)ans+=t[i];for(int i=1;i<n;i+=2)ans+=t[i];cout<<ans<<'\n';}

```

---

## 一句话总结

加密串按左右交替生成，解密时按奇偶位置逆序取回。
