# ABC464 E - Fill-Rect Query

## 网址

https://atcoder.jp/contests/abc464/tasks/abc464_e

## 题解

有 `Q` 次操作，每次把左上角前缀矩形 `(1,1)~(R,C)` 填成字符 `X`。要求最终网格。

对每个格子 `(i,j)`，最终颜色来自所有满足：

```text
R >= i 且 C >= j
```

的操作中时间最晚的那个操作。也就是说，若把每个操作编号 `t` 放在位置 `(R,C)`，那么每个格子需要右下方向所有点中的最大编号。

建立数组 `last`，`last[R-1][C-1]=t`。然后从右下往左上做二维后缀最大：

```text
last[i][j] = max(last[i][j], last[i+1][j], last[i][j+1])
```

最终格子 `(i,j)` 的字符就是编号 `last[i][j]` 对应的字符。编号为 `0` 表示从未被覆盖，使用初始字符 `A`。

时间复杂度：`O(HW+Q)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> last(H, vector<int>(W, 0));
    vector<char> color(Q + 1, 'A');

    for (int t = 1; t <= Q; t++) {
        int R, C;
        cin >> R >> C >> color[t];
        --R;
        --C;
        last[R][C] = max(last[R][C], t);
    }

    for (int i = H - 1; i >= 0; i--) {
        for (int j = W - 1; j >= 0; j--) {
            if (i + 1 < H) last[i][j] = max(last[i][j], last[i + 1][j]);
            if (j + 1 < W) last[i][j] = max(last[i][j], last[i][j + 1]);
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << color[last[i][j]];
        }
        cout << '\n';
    }

    return 0;
}
```

## 样例验证

代码把每个格子的最终操作转成右下后缀最大值。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
