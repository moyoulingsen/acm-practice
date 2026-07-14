#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

class CHugeInt
{
public:
    string s;
    CHugeInt(int a)
    {
        s = to_string(a);
    }
    // CHugeInt(char *a)
    CHugeInt(const char *a)
    {
        s = a;
    }
    CHugeInt(string a)
    {
        s = a;
    }
    // CHugeInt operator+(CHugeInt &other)
    CHugeInt operator+(const CHugeInt &other) const

    {
        
        // string a =reserve(s.begin(),s.end());
        // string b =reserve(other.s.begin(),other.s.end());
        string a = s;
        reverse(a.begin(), a.end());
        string b = other.s;
        reverse(b.begin(), b.end());

        string ans = "";
        int carry = 0;
        int n = a.size(), m = b.size();
        int len = max(n, m);

        for (int i = 0; i < len; i++)
        {
            int x = (i < n ? a[i] - '0' : 0);
            int y = (i < m ? b[i] - '0' : 0);
            int sum = x + y + carry;
            ans += char(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)ans += char(carry + '0');
            reverse(ans.begin(), ans.end());
            // return retun(ans);
            return CHugeInt(ans);
    }
    


    // friend ostream& operator<<(ostream& os,CHugeInt& a){
    friend ostream& operator<<(ostream& os, const CHugeInt& a){
        os<<a.s;
        return os;
    }
};

// CHugeInt operator+(CHugeInt &other,int num)
CHugeInt operator+(const CHugeInt &other, int num)

    {
        
        // string a =reserve(s.begin(),s.end());
        // string b =reserve(other.s.begin(),other.s.end());
        string a = other.s;
        reverse(a.begin(), a.end());
        string b = to_string(num);
        reverse(b.begin(), b.end());

        string ans = "";
        int carry = 0;
        int n = a.size(), m = b.size();
        int len = max(n, m);

        for (int i = 0; i < len; i++)
        {
            int x = (i < n ? a[i] - '0' : 0);
            int y = (i < m ? b[i] - '0' : 0);
            int sum = x + y + carry;
            ans += char(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)ans += char(carry + '0');
            reverse(ans.begin(), ans.end());
            // return retun(ans);
            return CHugeInt(ans);
    }
    //  CHugeInt operator+(int num,CHugeInt &other)
CHugeInt operator+(int num, const CHugeInt &other)

    {
        
        // string a =reserve(s.begin(),s.end());
        // string b =reserve(other.s.begin(),other.s.end());
        string a = to_string(num);
        reverse(a.begin(), a.end());
        string b = other.s;
        reverse(b.begin(), b.end());

        string ans = "";
        int carry = 0;
        int n = a.size(), m = b.size();
        int len = max(n, m);

        for (int i = 0; i < len; i++)
        {
            int x = (i < n ? a[i] - '0' : 0);
            int y = (i < m ? b[i] - '0' : 0);
            int sum = x + y + carry;
            ans += char(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)ans += char(carry + '0');
            reverse(ans.begin(), ans.end());
            // return retun(ans);
            return CHugeInt(ans);
    }

signed main()
{
    

    char s[210];
    int n;
    while (cin >> s >> n)
    {
        CHugeInt a(s);
        CHugeInt b(n);
        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
    }
    return 0;
}

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