#include <bits/stdc++.h>
using namespace std;

double s, a, b; // 距离、人速、车速

// 检验能否在 T 时间内让两人都到达
bool check(double T)
{
    // 甲的时间约束：x / b + (s - x) / a <= T
    // 因为 b > a，1/b - 1/a < 0，移项并除以负数时不等号反向
    // 得到 x >= (s/a - T) * (a * b / (b - a))
    double minX = 0.0;
    if (T < s / a)
    {
        minX = (s / a - T) * (a * b / (b - a));
    }
    // 如果必须的乘车距离已经超过全程，说明 T 太小，不可能
    if (minX > s + 1e-9)
        return false;

    // 为了让乙的时间尽量短，甲应该尽可能少乘车（但必须满足甲的时间）
    // 所以我们取最小的可行乘车距离 x = minX
    double x = max(0.0, minX); // 确保非负

    // 乙的时间计算
    double t1 = x / b;                   // 甲乘车期间，乙步行
    double t2 = (x - a * t1) / (b + a);  // 车返回接乙的时间
    double t3 = (s - a * (t1 + t2)) / b; // 乙乘车到终点的时间
    double totalB = t1 + t2 + t3;

    return totalB <= T + 1e-9; // 允许微小浮点误差
}

int main()
{
    cin >> s >> a >> b;
    double l = s / b, r = s / a; // 最短时间：全程车；最长时间：全程人走
    for (int i = 0; i < 60; ++i)
    { // 二分 60 次足够精确到 1e-6
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(6) << r << endl;
    return 0;
}