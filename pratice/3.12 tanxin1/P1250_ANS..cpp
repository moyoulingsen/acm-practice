#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Demand {
    int b, e, t;
};

bool cmp(const Demand& a, const Demand& b) {
    return a.e < b.e;
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<Demand> demands(h);
    for (int i = 0; i < h; ++i) {
        cin >> demands[i].b >> demands[i].e >> demands[i].t;
    }
    // 按区间右端点排序
    sort(demands.begin(), demands.end(), cmp);
    vector<bool> planted(n + 1, false); // 位置 1..n 是否种树
    int total = 0;

    for (const auto& d : demands) {
        int cnt = 0;
        // 统计当前区间内已有的树
        for (int i = d.b; i <= d.e; ++i) {
            if (planted[i]) ++cnt;                              /////////////状态可以1，0简化
        }
        if (cnt >= d.t) continue; // 已满足要求
        int need = d.t - cnt;
        // 从右向左在空位种树，尽量覆盖后续区间
        for (int i = d.e; i >= d.b && need > 0; --i) {
            if (!planted[i]) {
                planted[i] = true;
                --need;
                ++total;
            }
        }
    }
    cout << total << endl;
    return 0;
}