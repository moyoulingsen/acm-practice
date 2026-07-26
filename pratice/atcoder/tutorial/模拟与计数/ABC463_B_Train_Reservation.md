# ABC463 B - Train Reservation

## 网址

https://atcoder.jp/contests/abc463/tasks/abc463_b

## 题解

每辆列车的座位状态用长度为 `5` 的字符串表示，列名为 `A` 到 `E`。把目标列 `X` 转成下标 `X - 'A'`，然后检查所有列车在这一列是否存在空位 `o`。

只要有一辆列车满足 `S[idx] == 'o'`，答案就是 `Yes`；否则是 `No`。

时间复杂度：`O(N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    char X;
    cin >> N >> X;

    int idx = X - 'A';
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (S[idx] == 'o') {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}
```

## 样例验证

代码逐行检查目标座位列，和题意中的“是否存在一辆车有空位”完全一致。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
