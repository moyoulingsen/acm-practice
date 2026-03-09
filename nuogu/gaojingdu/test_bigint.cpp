#include <bits/stdc++.h>

#if __has_include("tool/local.hpp")
    #include "tool/local.hpp"
#else
    #define debug(...) 42
#endif

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using f80 = long double;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

constexpr int INF = 1e9 + 7;
constexpr i64 INF64 = 4e18;

struct BigInt {
    static const int BASE = 1e9;
    vector<int> v;
    BigInt() { v.push_back(0); }
    BigInt(long long val) {
        if (val == 0) v.push_back(0);
        while (val > 0) { v.push_back(val % BASE); val /= BASE; }
    }
    BigInt(string s) {
        if (s.empty()) { v.push_back(0); return; }
        for (int i = (int)s.length(); i > 0; i -= 9) {
            if (i < 9) v.push_back(stoi(s.substr(0, i)));
            else v.push_back(stoi(s.substr(i - 9, 9)));
        }
        trim();
    }
    void trim() { while (v.size() > 1 && v.back() == 0) v.pop_back(); }
    bool operator<(const BigInt& b) const {
        if (v.size() != b.v.size()) return v.size() < b.v.size();
        for (int i = (int)v.size() - 1; i >= 0; i--) {
            if (v[i] != b.v[i]) return v[i] < b.v[i];
        }
        return false;
    }
    bool operator<=(const BigInt& b) const { return !(b < *this); }
    bool operator==(const BigInt& b) const { return !(*this < b) && !(b < *this); }
    BigInt operator+(const BigInt& b) const {
        BigInt res; res.v.clear();
        int carry = 0;
        for (int i = 0; i < max(v.size(), b.v.size()) || carry; ++i) {
            if (i < v.size()) carry += v[i];
            if (i < b.v.size()) carry += b.v[i];
            res.v.push_back(carry % BASE);
            carry /= BASE;
        }
        return res;
    }
    BigInt operator-(const BigInt& b) const {
        BigInt res; res.v.clear();
        int borrow = 0;
        for (int i = 0; i < v.size(); ++i) {
            int sub = v[i] - borrow - (i < b.v.size() ? b.v[i] : 0);
            if (sub < 0) { sub += BASE; borrow = 1; }
            else borrow = 0;
            res.v.push_back(sub);
        }
        res.trim();
        return res;
    }
    BigInt operator*(const BigInt& b) const {
        BigInt res;
        res.v.assign(v.size() + b.v.size(), 0);
        for (int i = 0; i < v.size(); ++i) {
            long long carry = 0;
            for (int j = 0; j < b.v.size() || carry; ++j) {
                long long cur = res.v[i + j] + v[i] * 1LL * (j < b.v.size() ? b.v[j] : 0) + carry;
                res.v[i + j] = cur % BASE;
                carry = cur / BASE;
            }
        }
        res.trim();
        return res;
    }
    BigInt operator*(int b) const {
        BigInt res; res.v.clear();
        long long carry = 0;
        for (int i = 0; i < v.size() || carry; ++i) {
            long long cur = carry + (i < v.size() ? v[i] * 1LL * b : 0);
            res.v.push_back(cur % BASE);
            carry = cur / BASE;
        }
        res.trim();
        return res;
    }
    BigInt operator/(const BigInt& b) const {
        BigInt res, rem;
        res.v.assign(v.size(), 0);
        rem.v.clear();
        for (int i = (int)v.size() - 1; i >= 0; --i) {
            rem.v.insert(rem.v.begin(), v[i]);
            rem.trim();
            int L = 0, R = BASE - 1, ans = 0;
            while (L <= R) {
                int mid = L + (R - L) / 2;
                if (b * mid <= rem) {
                    ans = mid; L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
            res.v[i] = ans;
            rem = rem - (b * ans);
        }
        res.trim();
        return res;
    }
    void print() const {
        cout << v.back();
        for (int i = (int)v.size() - 2; i >= 0; --i) cout << setfill('0') << setw(9) << v[i];
    }
};

void solve() {
    
string s1, s2;
cin >> s1 >> s2;

BigInt a(s1), b(s2);

cout << "A + B = "; (a + b).print(); cout << endl;

if (b <= a) {
cout << "A - B = "; (a - b).print(); cout << endl;
}

cout << "A * B = "; (a * b).print(); cout << endl;

if (!(b == BigInt(0))) {
cout << "A / B = "; (a / b).print(); cout << endl;
}


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     (void)!freopen("data.in", "r", stdin);
    //     (void)!freopen("data.out", "w", stdout);
    // #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}