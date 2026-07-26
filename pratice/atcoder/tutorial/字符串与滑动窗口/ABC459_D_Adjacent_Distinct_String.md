# ABC459 D - Adjacent Distinct String

## 网址

https://atcoder.jp/contests/abc459/tasks/abc459_d

## 题解

要重排字符串，使任意相邻两个字符都不同。

必要条件：任意字符出现次数不能超过：

```text
ceil(N/2) = (N+1)/2
```

否则最多的字符一定有两个相邻。

这个条件也是充分的。构造时每次选择剩余次数最多、且不同于上一个放入字符的字符。由于只有 `26` 个小写字母，每一位直接扫描所有字母即可。

时间复杂度：`O(26N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        int N = (int)S.size();
        vector<int> cnt(26);
        for (char c : S) cnt[c - 'a']++;

        if (*max_element(cnt.begin(), cnt.end()) > (N + 1) / 2) {
            cout << "No\n";
            continue;
        }

        string ans;
        int prev = -1;

        for (int pos = 0; pos < N; pos++) {
            int best = -1;
            for (int c = 0; c < 26; c++) {
                if (c == prev || cnt[c] == 0) continue;
                if (best == -1 || cnt[c] > cnt[best]) best = c;
            }

            ans.push_back(char('a' + best));
            cnt[best]--;
            prev = best;
        }

        cout << "Yes\n" << ans << '\n';
    }

    return 0;
}
```

## 样例验证

代码先判断最大频率条件，再贪心构造相邻不同字符串。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
