# ABC453 A - Trimo

## 网址

https://atcoder.jp/contests/abc453/tasks/abc453_a

## 题解

删除字符串开头连续的所有字符 `o`，输出剩余后缀。如果整个字符串都是 `o`，输出空行。

从左到右找到第一个不是 `o` 的位置 `p`，输出 `S.substr(p)` 即可。

时间复杂度：`O(N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int p = 0;
    while (p < N && S[p] == 'o') p++;
    cout << S.substr(p) << '\n';
    return 0;
}
```

## 样例验证

```text
输入
7
ooparts

输出
parts
```

```text
输入
6
abcooo

输出
abcooo
```

```text
输入
5
ooooo

输出

```
