# Edu 188 A - Passing the Ball

**题目链接**：<https://codeforces.com/problemset/problem/2204/A>

**题型**：模拟 / 字符串

**难度**：800

---

## 题意压缩

每个人按字符串中的方向传球，问过程中能接到球的不同人数有多少。

---

## 关键观察

如果出现相邻的 `RL`，球会在这两个位置之间来回传，后面的人永远接不到球。

所以只需要找第一次出现的 `RL`：

- 如果不存在，球能一路传到所有人，答案是 `n`；
- 如果第一次出现在位置 `pos`，答案是 `pos + 2`。

这里 `pos` 是从 `0` 开始的下标。

---

## 思路步骤

1. 扫描字符串找第一次 `RL`。
2. 找不到输出 `n`。
3. 找到则输出左端下标加 `2`。

---

## 复杂度

`O(n)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        size_t pos = s.find("RL");
        if (pos == string::npos) cout << n << '\n';
        else cout << (int)pos + 2 << '\n';
    }

    return 0;
}
```

---

## 一句话总结

第一次出现 `RL` 的位置会形成来回传球的“墙”，墙后面的人接不到球。
