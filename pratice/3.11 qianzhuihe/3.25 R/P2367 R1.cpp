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

    int mmin = d[1];    //这里要小心哦,a[1]就变回去了，mmin就出错了
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + d[i];
        mmin = min(mmin, a[i]);
    }

    cout << mmin;
    return 0;
}