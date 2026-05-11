# ACM 线下比赛板子（代码 + 必要说明）

目标：短、稳、快翻。  
原则：只带高频板子，不写百科全书。

## 0. 使用建议

- 默认不要 `#define int long long`
- 下标、点编号、边编号用 `int`
- 权值、答案、前缀和、距离用 `long long`
- `A*` 和链表优先级不高，页数紧就删
- 高精度只抄你会用到的操作，不要全抄满

---

## 1. 万能题头

说明：

- 这份题头已经够大多数题直接开写
- `chmin/chmax`、`qpow`、`exgcd`、`inv_mod` 都很高频

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)4e18;

template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll qpow(ll a, ll b, ll mod) {
    ll res = 1 % mod;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll inv_mod(ll a, ll mod) {
    ll x, y;
    ll d = exgcd(a, mod, x, y);
    if (d != 1) return -1;
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
```

---

## 2. STL 容器、内置语法、`algorithm`

说明：

- 比赛只记最常用写法
- `multiset` 删一个值时，别直接 `erase(x)`，那会删光所有 `x`
- `unordered_set` 平均 `O(1)`，但在极端数据下不如 `set` 稳

```cpp
vector<int> a;
a.push_back(x);
a.pop_back();
sort(a.begin(), a.end());
reverse(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
lower_bound(a.begin(), a.end(), x);
upper_bound(a.begin(), a.end(), x);

set<int> s;
s.insert(x);
s.erase(x);
s.count(x);
s.find(x);

multiset<int> ms;
ms.insert(x);
ms.erase(ms.find(x)); // 只删一个，前提是找得到

map<int, int> mp;
mp[x]++;
mp.count(x);
mp.erase(x);

multimap<int, int> mmp;
mmp.insert({k, v});

unordered_set<int> us;
us.insert(x);
us.count(x);

queue<int> q;
q.push(x);
q.front();
q.pop();

deque<int> dq;
dq.push_front(x);
dq.push_back(x);
dq.front();
dq.back();
dq.pop_front();
dq.pop_back();

stack<int> st;
st.push(x);
st.top();
st.pop();

priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int>> mn;
```

`algorithm` 里最常用的：

```cpp
sort(a.begin(), a.end());
reverse(a.begin(), a.end());
*min_element(a.begin(), a.end());
*max_element(a.begin(), a.end());
accumulate(a.begin(), a.end(), 0LL);
count(a.begin(), a.end(), x);
binary_search(a.begin(), a.end(), x);
next_permutation(a.begin(), a.end());
```

---

## 3. 额外高频补充：前缀和、差分、二分答案

说明：

- 这三类题在线下赛出现频率很高
- 区间和先想前缀和，区间修改先想差分，答案有单调性先想二分

前缀和：

```cpp
vector<ll> pre(n + 1, 0);
for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];

// [l, r] 区间和
ll sum = pre[r] - pre[l - 1];
```

差分：

```cpp
vector<ll> diff(n + 2, 0);

// [l, r] 全部加 x
diff[l] += x;
diff[r + 1] -= x;

for (int i = 1; i <= n; ++i) {
    diff[i] += diff[i - 1];
    a[i] += diff[i];
}
```

二分答案：

```cpp
int l = 0, r = 1e9;
while (l < r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
}
// l 就是最小可行解
```

如果是找最大可行解：

```cpp
int l = 0, r = 1e9;
while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (check(mid)) l = mid;
    else r = mid - 1;
}
// l 就是最大可行解
```

---

## 4. BFS

说明：

- 无权图最短路
- 网格最短路也常直接套这个

```cpp
vector<int> bfs(const vector<vector<int>>& g, int s) {
    int n = (int)g.size();
    vector<int> dist(n, INF);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist;
}
```

网格 BFS 常用方向数组：

```cpp
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
```

---

## 5. DFS（含内存优化）

说明：

- 递归 DFS 在大图上容易爆栈
- 线下赛更建议背迭代版

```cpp
vector<int> dfs_iterative(const vector<vector<int>>& g, int s) {
    int n = (int)g.size();
    vector<int> vis(n, 0), order;
    stack<int> st;
    st.push(s);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        order.push_back(u);
        for (int i = (int)g[u].size() - 1; i >= 0; --i) {
            int v = g[u][i];
            if (!vis[v]) st.push(v);
        }
    }
    return order;
}
```

DFS 内存优化要点：

- 大图优先手写 `stack`
- 邻接表尽量不要开在函数局部超大数组里
- 再大一档才考虑前向星

---

## 6. Dijkstra

说明：

- 只适用于非负边最短路
- 常见写法是 `priority_queue + 反复松弛`

```cpp
vector<ll> dijkstra(const vector<vector<pair<int, int>>>& g, int s) {
    int n = (int)g.size();
    vector<ll> dist(n, LINF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

---

## 7. 负权图算法：Bellman-Ford

说明：

- 有负边时可以用
- 还能判负环
- 比 `SPFA` 更稳，适合板子

```cpp
struct BellmanFordEdge {
    int u, v;
    ll w;
};

// 若从 s 可达负环，返回 false
bool bellman_ford(int n, int s, const vector<BellmanFordEdge>& edges, vector<ll>& dist) {
    dist.assign(n, LINF);
    dist[s] = 0;
    for (int i = 1; i < n; ++i) {
        bool any = false;
        for (auto [u, v, w] : edges) {
            if (dist[u] == LINF) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                any = true;
            }
        }
        if (!any) break;
    }
    for (auto [u, v, w] : edges) {
        if (dist[u] != LINF && dist[v] > dist[u] + w) return false;
    }
    return true;
}
```

---

## 8. A*

说明：

- 不是常规主力
- 只有启发函数容易写、而且明显能加速时才带
- 网格题多数情况下 `BFS` 就够了

```cpp
int astar_grid(const vector<string>& g, pii s, pii t) {
    int n = (int)g.size(), m = (int)g[0].size();
    auto h = [&](int x, int y) {
        return abs(x - t.first) + abs(y - t.second);
    };
    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<tuple<int, int, int, int>,
                   vector<tuple<int, int, int, int>>,
                   greater<tuple<int, int, int, int>>> pq;
    dist[s.first][s.second] = 0;
    pq.push({h(s.first, s.second), 0, s.first, s.second});
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (!pq.empty()) {
        auto [f, d, x, y] = pq.top();
        pq.pop();
        (void)f;
        if (d != dist[x][y]) continue;
        if (pii{x, y} == t) return d;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] == '#') continue;
            if (dist[nx][ny] > d + 1) {
                dist[nx][ny] = d + 1;
                pq.push({dist[nx][ny] + h(nx, ny), dist[nx][ny], nx, ny});
            }
        }
    }
    return -1;
}
```

---

## 9. 并查集

说明：

- 判断连通
- 动态合并集合
- Kruskal
- 网格连通块

必会接口：

- `find(x)`
- `unite(a, b)`
- `same(a, b)`
- `size(x)`

```cpp
struct DSU {
    vector<int> p, sz;
    DSU() {}
    explicit DSU(int n) { init(n); }
    void init(int n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
    bool same(int a, int b) { return find(a) == find(b); }
    int size(int x) { return sz[find(x)]; }
};
```

---

## 10. 链表

说明：

- ACM 里真正高频的是数组模拟链表
- `std::list` 很少是最优解
- 这里放双链表，适合 O(1) 插删

```cpp
struct LinkedList {
    vector<int> e, l, r;
    int idx;
    explicit LinkedList(int n) : e(n + 5), l(n + 5), r(n + 5), idx(2) {
        r[0] = 1;
        l[1] = 0;
    }
    void insert_right(int k, int x) {
        e[idx] = x;
        l[idx] = k;
        r[idx] = r[k];
        l[r[k]] = idx;
        r[k] = idx++;
    }
    void remove(int k) {
        r[l[k]] = r[k];
        l[r[k]] = l[k];
    }
};
```

---

## 11. 背包

### 11.1 01 背包

说明：

- 每个物品最多选一次
- 核心是 `j` 从大到小

```cpp
ll zero_one_knapsack(int m, const vector<int>& v, const vector<int>& w) {
    vector<ll> dp(m + 1, 0);
    int n = (int)v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= v[i]; --j) {
            chmax(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    return dp[m];
}
```

### 11.2 完全背包

说明：

- 每个物品可无限选
- 核心是 `j` 从小到大

```cpp
ll complete_knapsack(int m, const vector<int>& v, const vector<int>& w) {
    vector<ll> dp(m + 1, 0);
    int n = (int)v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = v[i]; j <= m; ++j) {
            chmax(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    return dp[m];
}
```

### 11.3 多重背包

说明：

- 每个物品有数量限制
- 板子建议背二进制拆分

```cpp
ll multiple_knapsack(int m, const vector<int>& v, const vector<int>& w, const vector<int>& c) {
    vector<ll> dp(m + 1, 0);
    int n = (int)v.size();
    for (int i = 0; i < n; ++i) {
        int cnt = c[i];
        for (int k = 1; cnt > 0; k <<= 1) {
            int take = min(k, cnt);
            int vv = v[i] * take;
            int ww = w[i] * take;
            for (int j = m; j >= vv; --j) {
                chmax(dp[j], dp[j - vv] + ww);
            }
            cnt -= take;
        }
    }
    return dp[m];
}
```

### 11.4 分组背包

说明：

- 每组最多选一个

```cpp
ll group_knapsack(int m, const vector<vector<pair<int, int>>>& groups) {
    vector<ll> dp(m + 1, 0);
    for (const auto& group : groups) {
        vector<ll> ndp = dp;
        for (auto [v, w] : group) {
            for (int j = m; j >= v; --j) {
                chmax(ndp[j], dp[j - v] + w);
            }
        }
        dp.swap(ndp);
    }
    return dp[m];
}
```

### 11.5 二维费用背包

说明：

- 这就是你问的“还能补什么背包”里最常见的一类
- 两维都从大到小

```cpp
ll two_dim_knapsack(int V, int M, const vector<int>& v, const vector<int>& m, const vector<int>& w) {
    vector<vector<ll>> dp(V + 1, vector<ll>(M + 1, 0));
    int n = (int)v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = V; j >= v[i]; --j) {
            for (int k = M; k >= m[i]; --k) {
                chmax(dp[j][k], dp[j - v[i]][k - m[i]] + w[i]);
            }
        }
    }
    return dp[V][M];
}
```

背包循环方向速记：

- `01 背包`：从大到小
- `完全背包`：从小到大
- `多重背包`：拆分后按 `01`
- `分组背包`：每组最多一个
- `二维费用背包`：双维都从大到小

---

## 12. 高精度

说明：

- 用哪个抄哪个
- 高频顺序一般是：加、减、乘、除以 `int`
- 高精除高精很少考，不建议占纸面

### 12.1 去前导零和比较

```cpp
string strip_zero(string s) {
    int p = 0;
    while (p + 1 < (int)s.size() && s[p] == '0') ++p;
    return s.substr(p);
}

int cmp_big(string a, string b) {
    a = strip_zero(a);
    b = strip_zero(b);
    if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    if (a == b) return 0;
    return a < b ? -1 : 1;
}
```

### 12.2 高精加法

```cpp
string add_big(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c;
    int t = 0;
    for (int i = 0; i < (int)max(a.size(), b.size()) || t; ++i) {
        if (i < (int)a.size()) t += a[i] - '0';
        if (i < (int)b.size()) t += b[i] - '0';
        c.push_back(char('0' + t % 10));
        t /= 10;
    }
    while (c.size() > 1 && c.back() == '0') c.pop_back();
    reverse(c.begin(), c.end());
    return c;
}
```

### 12.3 高精减法

说明：默认 `a >= b`，而且都非负。

```cpp
string sub_big(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c;
    int t = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        t = a[i] - '0' - t;
        if (i < (int)b.size()) t -= b[i] - '0';
        c.push_back(char('0' + (t + 10) % 10));
        t = t < 0;
    }
    while (c.size() > 1 && c.back() == '0') c.pop_back();
    reverse(c.begin(), c.end());
    return c;
}
```

### 12.4 高精乘法

```cpp
string mul_big(string a, string b) {
    a = strip_zero(a);
    b = strip_zero(b);
    vector<int> c(a.size() + b.size(), 0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < (int)a.size(); ++i) {
        for (int j = 0; j < (int)b.size(); ++j) {
            c[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = 0; i + 1 < (int)c.size(); ++i) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    string s;
    for (int i = (int)c.size() - 1; i >= 0; --i) s.push_back(char('0' + c[i]));
    return s;
}
```

### 12.5 高精除以 `int`

说明：返回 `商` 和 `余数`。

```cpp
pair<string, int> div_big_int(const string& a, int b) {
    string q;
    int r = 0;
    for (char ch : a) {
        r = r * 10 + (ch - '0');
        q.push_back(char('0' + r / b));
        r %= b;
    }
    return {strip_zero(q), r};
}
```

---

## 13. 数论

### 13.1 快速幂

说明：

- 求 `a^b mod mod`
- 求质数模下逆元时直接复用

```cpp
ll qpow(ll a, ll b, ll mod) {
    ll res = 1 % mod;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
```

### 13.2 `gcd / lcm`

说明：

- `gcd(a, b)` 直接用 `std::gcd(a, b)`
- `lcm(a, b) = a / gcd(a, b) * b`

```cpp
ll g = gcd(a, b);
ll l = a / g * b;
```

### 13.3 斐蜀定理 + 扩展欧几里得

要记的一句话：

`ax + by = gcd(a, b)` 有整数解。

```cpp
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
```

### 13.4 逆元

说明：

- 如果 `mod` 是质数：`a^(mod-2) mod mod`
- 一般情况且 `gcd(a, mod) = 1`：扩欧

```cpp
ll inv_mod(ll a, ll mod) {
    ll x, y;
    ll d = exgcd(a, mod, x, y);
    if (d != 1) return -1;
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
```

质数模下也可以这样写：

```cpp
ll inv_prime_mod(ll a, ll mod) {
    return qpow(a, mod - 2, mod);
}
```

### 13.5 质数筛

```cpp
vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            if ((ll)i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
    return primes;
}
```

### 13.6 异或性质

板子上记这些就够：

- `a ^ a = 0`
- `a ^ 0 = a`
- 满足交换律、结合律
- 前缀异或可以做区间异或
- 一个数出现偶数次会被抵消

常见用途：

- 找唯一只出现一次的数
- 状压
- 构造

---

## 14. 我建议你额外带上的两个高频板子

### 14.1 拓扑排序

说明：

- DAG
- 先修关系
- 依赖关系
- 判是否有环

```cpp
vector<int> topo_sort(int n, const vector<vector<int>>& g) {
    vector<int> indeg(n), order;
    queue<int> q;
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) ++indeg[v];
    }
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if ((int)order.size() != n) return {};
    return order;
}
```

### 14.2 树状数组

说明：

- 单点修改
- 前缀和
- 区间和
- 比线段树更短，线下很值得带

```cpp
struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick() {}
    explicit Fenwick(int n) { init(n); }
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    ll sum_prefix(int idx) const {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    ll range_sum(int l, int r) const {
        if (l > r) return 0;
        return sum_prefix(r) - sum_prefix(l - 1);
    }
};
```

---

## 15. 最后精简建议

如果线下赛纸面页数很紧，优先留下这些：

1. 万能题头
2. STL 容器 + `algorithm`
3. 前缀和 / 差分 / 二分
4. BFS / 迭代 DFS / Dijkstra / Bellman-Ford
5. 并查集
6. `01 / 完全 / 多重 / 分组` 背包
7. 高精加减乘除 `int`
8. 快速幂 / 扩欧 / 逆元 / 筛 / 异或

优先删掉：

1. `A*`
2. 链表
3. 二维费用背包

