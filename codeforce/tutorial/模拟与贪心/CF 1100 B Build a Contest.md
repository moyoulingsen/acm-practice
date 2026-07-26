# CF 1100 B - Build a Contest

**题目链接**：<https://codeforces.com/problemset/problem/1100/B>

**题型**：计数 / 模拟

---

## 题意压缩

维护每个难度库存；当所有难度都有至少一个时输出 1 并每类消耗一个，否则输出 0。

---

## 关键观察

维护每个难度库存；当所有难度都有至少一个时输出 1 并每类消耗一个，否则输出 0。

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

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<int>cnt(n+1);int have=0;string ans;for(int i=0;i<m;i++){int x;cin>>x;if(cnt[x]++==0)have++;if(have==n){ans+='1';for(int d=1;d<=n;d++)if(--cnt[d]==0)have--;}else ans+='0';}cout<<ans<<'\n';}

```

---

## 一句话总结

维护每个难度库存；当所有难度都有至少一个时输出 1 并每类消耗一个，否则输出 0。
