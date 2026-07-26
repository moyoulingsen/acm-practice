# CF 1104 B - Game with string

**题目链接**：<https://codeforces.com/problemset/problem/1104/B>

**题型**：字符串 / 栈 / 博弈

---

## 题意压缩

用栈消掉相邻相同字符，消掉次数为奇数则先手赢。

---

## 关键观察

用栈消掉相邻相同字符，消掉次数为奇数则先手赢。

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

int main(){string s;cin>>s;vector<char>st;int mv=0;for(char c:s){if(!st.empty()&&st.back()==c)st.pop_back(),mv++;else st.push_back(c);}cout<<(mv%2?"Yes":"No")<<'\n';}

```

---

## 一句话总结

用栈消掉相邻相同字符，消掉次数为奇数则先手赢。
