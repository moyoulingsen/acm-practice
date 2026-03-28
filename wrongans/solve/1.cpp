#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> d(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = a[i] - a[i - 1];
    }

    while (p--) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }

    int mmin = a[1];
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + d[i];
        mmin = min(mmin, a[i]);
    }

    cout << mmin;
    return 0;
}

/*
3 2
1 1 1
1 2 1
2 3 1
2
*/


































































//////////因为原来的a[1];就是没有修改的啊。你不能能用这个mmin的初始值
