#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    // 将二维下标 id = i*N + j
int n = M * N;
vector<bitset<225>> a(n); // 系数矩阵，每行 n+1 列（最后一列为常数）
for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
        int id = i*N + j;
        a[id].set(id);               // 自身
        if (i > 0) a[id].set((i-1)*N + j);
        if (i < M-1) a[id].set((i+1)*N + j);
        if (j > 0) a[id].set(i*N + (j-1));
        if (j < N-1) a[id].set(i*N + (j+1));
        // 常数项 = 初始状态
        if (grid[i][j] == 1) a[id].set(n);  // 1 表示需要翻转奇数次
    }
}

// 高斯消元
int row = 0;
vector<int> where(n, -1);
for (int col = 0; col < n && row < n; col++) {
    // 找主元
    int sel = row;
    while (sel < n && !a[sel][col]) sel++;
    if (sel == n) continue;
    swap(a[row], a[sel]);
    where[col] = row;
    for (int i = row+1; i < n; i++) {
        if (a[i][col]) a[i] ^= a[row];
    }
    row++;
}

// 检查无解
for (int i = row; i < n; i++) {
    if (a[i][n]) { cout << "IMPOSSIBLE\n"; return; }
}

// 回代（如果有自由变量，需要枚举）
vector<int> ans(n, 0);
for (int i = n-1; i >= 0; i--) {
    if (where[i] == -1) continue; // 自由变量，稍后枚举
    int r = where[i];
    int sum = a[r][n];
    for (int j = i+1; j < n; j++) {
        if (a[r][j]) sum ^= ans[j];
    }
    ans[i] = sum;
}
// 此时 ans 是一个解（若自由变量全取 0）
// 若要最小解，需枚举自由变量
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