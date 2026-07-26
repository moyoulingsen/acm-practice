# ABC455 D - Card Pile Query

## 网址

https://atcoder.jp/contests/abc455/tasks/abc455_d

## 题解

给每个牌堆加一个永不移动的虚拟底牌 `N+i`。维护双向链表：

- `up[x]`：卡牌 `x` 正上方的牌；
- `down[x]`：卡牌 `x` 正下方的牌。

操作将 `C` 以及它上方所有牌移动到 `P` 上方。设 `D=down[C]`，更新：

```text
down[C] = P
up[P] = C
up[D] = -1
```

最后从每个虚拟底牌沿 `up` 往上走，统计真实卡牌数量。

时间复杂度：`O(N+Q)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> up(2 * N, -1), down(2 * N, -1);

    for (int i = 0; i < N; i++) {
        int card = i;
        int bottom = N + i;
        up[bottom] = card;
        down[card] = bottom;
    }

    while (Q--) {
        int C, P;
        cin >> C >> P;
        --C;
        --P;

        int D = down[C];
        down[C] = P;
        up[P] = C;
        up[D] = -1;
    }

    for (int i = 0; i < N; i++) {
        int x = N + i;
        int cnt = 0;

        while (up[x] != -1) {
            x = up[x];
            cnt++;
        }

        if (i) cout << ' ';
        cout << cnt;
    }
    cout << '\n';

    return 0;
}
```

## 样例验证

```text
输入
5 4
1 3
4 5
1 4
4 2

输出
0 3 1 0 1
```

```text
输入
7 8
3 1
5 4
2 5
5 7
2 3
6 2
3 4
5 1

输出
2 0 0 4 0 0 1
```
