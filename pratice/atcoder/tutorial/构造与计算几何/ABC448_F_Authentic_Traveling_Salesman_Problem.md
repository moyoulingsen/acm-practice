# ABC448 F - Authentic Traveling Salesman Problem

## 网址

https://atcoder.jp/contests/abc448/tasks/abc448_f

## 题解

不需要求最短路，只要构造一条足够短的路线。

把平面按 `x` 坐标分成若干竖条，然后按竖条从左到右访问。每个竖条内部采用蛇形顺序：

- 偶数竖条按 `y` 升序；
- 奇数竖条按 `y` 降序。

这样可以避免在相邻竖条之间频繁上下跳，控制总曼哈顿距离。排序后把序列旋转到点 `1` 作为开头即可。

时间复杂度：`O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    const int W = 20000000;
    int B = max(1, (int)(W / sqrt((double)N)));

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](int i, int j) {
        int bi = X[i] / B;
        int bj = X[j] / B;
        if (bi != bj) return bi < bj;
        if (bi % 2 == 0) return Y[i] < Y[j];
        return Y[i] > Y[j];
    });

    int pos = find(ord.begin(), ord.end(), 0) - ord.begin();
    rotate(ord.begin(), ord.begin() + pos, ord.end());

    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << ord[i] + 1;
    }
    cout << '\n';

    return 0;
}
```

## 样例验证

代码为蛇形扫描构造。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
