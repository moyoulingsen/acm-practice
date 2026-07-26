# ABC452 A - Gothec

## 网址

https://atcoder.jp/contests/abc452/tasks/abc452_a

## 题解

五节句日期只有以下 5 个：

```text
1/7, 3/3, 5/5, 7/7, 9/9
```

直接判断输入的 `(M, D)` 是否属于这个集合即可。

时间复杂度：`O(1)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, D;
    cin >> M >> D;

    if ((M == 1 && D == 7) ||
        (M == 3 && D == 3) ||
        (M == 5 && D == 5) ||
        (M == 7 && D == 7) ||
        (M == 9 && D == 9)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
```

## 样例验证

```text
输入
3 3

输出
Yes
```

```text
输入
1 1

输出
No
```

```text
输入
4 4

输出
No
```

```text
输入
11 7

输出
No
```
