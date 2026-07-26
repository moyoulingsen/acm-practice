# ABC456 A - Dice

## 网址

https://atcoder.jp/contests/abc456/tasks/abc456_a

## 题解

三个普通六面骰的点数和最小是 `3`，最大是 `18`，并且中间每个整数都可以凑出。

因此只需要判断：

```text
3 <= X <= 18
```

时间复杂度：`O(1)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    cout << (3 <= X && X <= 18 ? "Yes" : "No") << '\n';
    return 0;
}
```

## 样例验证

```text
输入
15

输出
Yes
```

```text
输入
2

输出
No
```
