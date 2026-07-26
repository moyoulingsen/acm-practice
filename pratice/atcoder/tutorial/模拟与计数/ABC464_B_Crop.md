# ABC464 B - Crop

## 网址

https://atcoder.jp/contests/abc464/tasks/abc464_b

## 题解

题目要求删掉最外层全白行和全白列，直到剩下的图像边界都包含黑格。等价于找到所有 `#` 的最小外接矩形。

扫描整个网格，记录：

- 含 `#` 的最小行 `top`；
- 含 `#` 的最大行 `bottom`；
- 含 `#` 的最小列 `left`；
- 含 `#` 的最大列 `right`。

最后输出这个矩形区域即可。

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

    vector<string> C(H);
    for (auto &s : C) cin >> s;

    int top = H, bottom = -1;
    int left = W, right = -1;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (C[i][j] == '#') {
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }

    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            cout << C[i][j];
        }
        cout << '\n';
    }

    return 0;
}
```

## 样例验证

代码输出包含所有黑格的最小矩形，与反复裁掉全白边界等价。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
