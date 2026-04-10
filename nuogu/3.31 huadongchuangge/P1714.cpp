//最短最大

#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    int n,m;
    cin>>n>>m;

    vector<int> arr(n+1,0),s(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        s[i] = s[i-1]+arr[i];
    }
    int ans = LLONG_MIN;
    deque<int> q;
    for(int i = 1;i<=n;i++){
        while(!q.empty() && q.front()<=i-m ){
            q.pop_front();
        }
        while(!q.empty() && s[q.back()]<=s[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans = max(ans,s[i]-s[q.front()]);
    }
    cout<< ans;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}