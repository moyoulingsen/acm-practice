#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	r++;
	string s;
	cin >> s;
	ll ans = 0;
	vector<int> cnt(26);
	for (int i = 0; i < n; i++) {
		if (i >= l) cnt[s[i - l] - 'a']++;
		if (i >= r) cnt[s[i - r] - 'a']--;
		ans += cnt[s[i] - 'a'];
	}
	cout << ans << '\n';
}
