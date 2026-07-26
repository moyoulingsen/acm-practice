# ABC449 C - Comfortable Distance

## 网址

https://atcoder.jp/contests/abc449/tasks/abc449_c

## 题解

固定右端点 `j`，左端点 `i` 必须满足 `j-R <= i <= j-L`，并且 `S_i = S_j`。

从左到右扫描 `j`，维护当前合法左端点窗口内每个字符出现次数：

1. 当 `j >= L`，把 `S[j-L]` 加入窗口；
2. 当 `j >= R+1`，把 `S[j-R-1]` 移出窗口；
3. 当前贡献为 `cnt[S[j]]`。

时间复杂度：`O(N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R;
    string S;
    cin >> N >> L >> R >> S;

    vector<int> cnt(26);
    long long ans = 0;

    for (int j = 0; j < N; j++) {
        if (j >= L) cnt[S[j - L] - 'a']++;
        if (j >= R + 1) cnt[S[j - R - 1] - 'a']--;
        ans += cnt[S[j] - 'a'];
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码逐位维护合法距离窗口，能够直接对应题意中的 `L <= j-i <= R`。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
