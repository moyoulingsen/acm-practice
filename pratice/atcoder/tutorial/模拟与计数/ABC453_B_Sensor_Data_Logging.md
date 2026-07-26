# ABC453 B - Sensor Data Logging

## 网址

https://atcoder.jp/contests/abc453/tasks/abc453_b

## 题解

时刻 `0` 一定保存。之后维护 `last` 表示最近一次保存的读数，顺序扫描每个时刻 `i`：

```text
如果 |A_i - last| >= X，则保存这个时刻，并令 last = A_i
```

时间复杂度：`O(T)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, X;
    cin >> T >> X;

    int last;
    cin >> last;
    cout << 0 << ' ' << last << '\n';

    for (int i = 1; i <= T; i++) {
        int a;
        cin >> a;
        if (abs(a - last) >= X) {
            last = a;
            cout << i << ' ' << last << '\n';
        }
    }

    return 0;
}
```

## 样例验证

```text
输入
6 10
30 35 40 21 30 12 31

输出
0 30
2 40
3 21
6 31
```
