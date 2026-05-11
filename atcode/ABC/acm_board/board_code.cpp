#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
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

// ---------------- graph ----------------

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

// Iterative DFS: avoids recursion stack overflow on large graphs.
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

struct BellmanFordEdge {
    int u, v;
    ll w;
};

// Returns false if a negative cycle is reachable from s.
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

// A* on grid: '#' blocked, others passable, 4 directions.
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

// ---------------- dsu ----------------

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

// ---------------- linked list ----------------

// Double linked list by arrays, useful for O(1) insert/erase by index.
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

// ---------------- knapsack ----------------

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

// Multiple knapsack by binary splitting.
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

// Group knapsack: one item at most from each group.
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

// 2D knapsack: volume V, weight M.
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

// ---------------- bigint ----------------

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

// Requires a >= b, both nonnegative.
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

// Divides nonnegative bigint by positive int.
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

// ---------------- prime / xor ----------------

vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            if ((ll)i * i <= n) {
                for (int j = i * i; j <= n; j += i) is_prime[j] = false;
            }
        }
    }
    return primes;
}
