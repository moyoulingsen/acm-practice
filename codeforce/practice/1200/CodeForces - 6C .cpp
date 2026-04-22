#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    int l = 0;
    int r = n - 1;
    int s1 = 0;
    int s2 = 0;
    int a = 0;
    int b = 0;

    while (a + b < n)
    {
        if (s1 <= s2)
        {
            s1 += arr[l];
            l++;
            a++;
        }
        else
        {
            s2 += arr[r];
            r--;
            b++;
        }
    }
    cout << a << " " << b;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}

// Alice 和 Bob 都喜欢玩游戏。现在他们准备开始玩一个新游戏。他们把 \(n\) 根巧克力棒排成一行。Alice 从最左边开始一根接一根地往右吃，Bob 则从最右边开始一根接一根地往左吃。对于每一根巧克力棒，两人吃掉它所需的时间都是已知的（Alice 和 Bob 吃巧克力的速度一样快）。一个玩家吃完手中的巧克力棒后，会立刻拿起下一根开始吃。不允许两个人同时吃同一根巧克力棒，也不允许吃到一半放下或者中途停顿。如果两人恰好同时开始吃同一根巧克力棒，那么 Bob 会像个真正的绅士一样把它让给 Alice。

// 请问最终两人分别会吃掉多少根巧克力棒？

// **输入格式**
// 第一行包含一个整数 \(n\)（\(1 \le n \le 10^5\)），表示桌子上巧克力棒的数量。
// 第二行包含一个序列 \(t_1, t_2, \dots, t_n\)（\(1 \le t_i \le 1000\)），其中 \(t_i\) 表示吃掉从左往右数第 \(i\) 根巧克力棒所需要的秒数。

// **输出格式**
// 输出两个整数 \(a\) 和 \(b\)，其中 \(a\) 是 Alice 吃掉的巧克力棒数量，\(b\) 是 Bob 吃掉的巧克力棒数量。