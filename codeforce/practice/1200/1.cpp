#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int n;
vector<pair<int, int>> arr;
vector<int> vis;

void dfs(int k)
{
    vis[k] = 1;  // dfs只用写一个
    rep(j, 0, n) ////////这里很显然 图的连通性，与编号大小无关
    {
        if (!vis[j] && (arr[j].first == arr[k].first || arr[j].second == arr[k].second))
        {
            vis[j] = 1; // 这一个重复了
            dfs(j);
        }
    }
}

void solve()
{
    cin >> n;
    arr.resize(n);
    vis.resize(n);
    rep(i, 0, n)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    int cnt = 0;
    rep(i, 0, n)
    {
        if (!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt - 1;
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

// Bajtek is learning to skate on ice. He's a beginner, so his only mode of transportation is pushing off from a snow drift to the north, east, south or west and sliding until he lands in another snow drift. He has noticed that in this way it's impossible to get from some snow drifts to some other by any sequence of moves. He now wants to heap up some additional snow drifts, so that he can get from any snow drift to any other one. He asked you to find the minimal number of snow drifts that need to be created.

// We assume that Bajtek can only heap up snow drifts at integer coordinates.

// Input
// The first line of input contains a single integer n (1 ≤ n ≤ 100) — the number of snow drifts. Each of the following n lines contains two integers xi and yi (1 ≤ xi, yi ≤ 1000) — the coordinates of the i-th snow drift.

// Note that the north direction coinсides with the direction of Oy axis, so the east direction coinсides with the direction of the Ox axis. All snow drift's locations are distinct.

// Output
// Output the minimal number of snow drifts that need to be created in order for Bajtek to be able to reach any snow drift from any other one.

// Bajtek 正在学习在冰上滑行。由于他还是新手，他唯一的移动方式是：从一个雪堆出发，向北、东、南或西中的一个方向蹬出去，然后一直滑行，直到落到另一个雪堆上。

// 他注意到，用这种方式，有些雪堆之间无论经过怎样的移动序列都无法互相到达。于是他想再堆出一些新的雪堆，使得从任意一个雪堆都能够到达任意另一个雪堆。

// 你的任务是求出：最少需要新建多少个雪堆。

// 规定 Bajtek 只能在整数坐标处堆雪堆。

// 输入格式

// 第一行包含一个整数 n（1 ≤ n ≤ 100），表示现有雪堆的数量。

// 接下来 n 行，每行包含两个整数 xi 和 yi（1 ≤ xi, yi ≤ 1000），表示第 i 个雪堆的坐标。

// 保证所有雪堆的位置两两不同。

// 注意：北方向与 Oy 轴正方向一致，东方向与 Ox 轴正方向一致。

// 输出格式

// 输出一个整数，表示为了让 Bajtek 能够从任意一个雪堆到达任意另一个雪堆，最少需要新建的雪堆数量。