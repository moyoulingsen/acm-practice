#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    vector<long long> b(N);
    for (int i = 0; i < N; i++) {
        long long A;
        cin >> A;
        b[i] = A % K;
    }

    sort(b.begin(), b.end());

    long long maxGap = 0;
    for (int i = 0; i + 1 < N; i++) {
        maxGap = max(maxGap, b[i + 1] - b[i]);
    }
    maxGap = max(maxGap, b[0] + K - b[N - 1]); // 环形首尾差

    cout << K - maxGap << '\n';
    return 0;
}