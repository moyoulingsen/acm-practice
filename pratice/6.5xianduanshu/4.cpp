#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
struct Node {
    int c;
    int cf;
};
vector<int> arr;
vector<Node> tree,lazy;
Node merge(Node a, Node b) {
    Node ans;
    ans.c=a.c+b.c;
    ans.cf = a.cf+b.cf;
    return ans;
}

void apply(int p, int s, int t, int val) {
    tree[p] = (t - s + 1) * val;
    lazy[p] = val;
}

void push_down(int p, int s, int t) {
    if (!lazy[p]) return;
    int mid = s + ((t - s) >> 1);
    apply(p << 1, s, mid, lazy[p]);
    apply(p << 1 | 1, mid + 1, t, lazy[p]);
    lazy[p] = 0;
}

void build_tree(int s, int t, int p) {
    if (s == t) {
        tree[p] = arr[s];
        return;
    }
    int mid = s + ((t - s) >> 1);
    build_tree(s, mid, p << 1);
    build_tree(mid + 1, t, p << 1 | 1);
    tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
}

int find(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) {
        return tree[p];
    }
    push_down(p, s, t);
    int mid = s + ((t - s) >> 1);
    if (r <= mid) {
        return find(l, r, s, mid, p << 1);
    }
    if (l > mid) {
        return find(l, r, mid + 1, t, p << 1 | 1);
    }
    return merge(find(l, r, s, mid, p << 1), find(l, r, mid + 1, t, p << 1 | 1));
}

void update(int l, int r, int s, int t, int val, int p) {
    if (l <= s && t <= r) {
        apply(p, s, t, val);
        return;
    }
    push_down(p, s, t);
    int mid = s + ((t - s) >> 1);
    if (l <= mid) {
        update(l, r, s, mid, val, p << 1);
    }
    if (r > mid) {
        update(l, r, mid + 1, t, val, p << 1 | 1);
    }
    tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
}



void solve() {
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}




