//最大值窗格

#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> arr(n+1);   //下标访问，必须开空间
    for(int i =1 ;i<=n;i++){
        cin>>arr[i];
    }
    
    deque <int > q;
     for(int i = 1;i<=n;i++){
        while(!q.empty() && q.front()<= i - m){
            q.pop_front();
        }
        while(!q.empty() && arr[q.back()]>=arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i>=m) cout<<arr[q.front()]<<" ";
    }
    cout<<endl;

    deque<int> dq;
    for(int i = 1;i<=n;i++){
        while(!dq.empty() && dq.front()<= i - m){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=m) cout<<arr[dq.front()]<<" ";
    }

    

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}