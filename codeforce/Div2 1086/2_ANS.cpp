#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 队列用vector模拟，0-based，队首为索引0
    vector<int> q = a;
    int tar_idx = p - 1;          // 目标卡的当前索引
    int energy = m;
    int ans = 0;

    while (true) {
        if (tar_idx < k) {        // 目标卡在前k个位置
            int cost = q[tar_idx];
            if (energy < cost) break;
            energy -= cost;
            ans++;
            // 将目标卡移到队尾
            int val = q[tar_idx];
            q.erase(q.begin() + tar_idx);
            q.push_back(val);
            tar_idx = (int)q.size() - 1;   // 现在它在末尾
        } else {                  // 目标卡不在前k，需要打其他卡
            // 在前k个中找最小费用的卡（全部是非目标）
            int min_idx = 0;
            for (int i = 1; i < k; ++i) {
                if (q[i] < q[min_idx]) min_idx = i;
            }
            int cost = q[min_idx];
            if (energy < cost) break;
            energy -= cost;
            // 将这张卡移到队尾
            int val = q[min_idx];
            q.erase(q.begin() + min_idx);
            q.push_back(val);
            // 因为被删除的卡在目标卡之前，所以目标卡索引减1
            tar_idx--;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}