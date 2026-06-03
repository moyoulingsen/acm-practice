#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    vector<int> arr(n);
    rep(i,0,n)cin>>arr[i];

    multiset<int> st;
    st.insert(arr[0]);
    auto it = st.find(arr[0]);
    int mid = arr[0];
    cout << arr[0]<<endl;

    for(int i = 1;i+1<n;i+=2){
        st.insert(arr[i]);
        st.insert(arr[i+1]);

        bool a=arr[i]<mid,b=arr[i+1]<mid;
            if(a!=b){
                cout<<mid<<endl;
            }
            else if(a&&b){
                mid = *(--it);
                cout<<mid<<endl;
                
            }
            else {
                mid = *(++it);
                cout<<mid<<endl;
            }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}