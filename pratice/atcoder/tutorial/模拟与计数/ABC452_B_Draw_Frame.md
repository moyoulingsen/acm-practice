# ABC452 B - Draw Frame

## 网址

https://atcoder.jp/contests/abc452/tasks/abc452_b

## 题解

输出一个 `H x W` 的矩形框。边界格子输出 `#`，内部格子输出 `.`。

一个格子在边界当且仅当：

```text
i == 0 或 i == H-1 或 j == 0 或 j == W-1
```

时间复杂度：`O(HW)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
4 5

输出
#####
#...#
#...#
#####
```

```text
输入
5 6

输出
######
#....#
#....#
#....#
######
```
