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
    rep(i,0,n){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    
    int ans1 =0;
    int r =n-1;
    int l =0;
    int rest =n;
    while(rest>0){
        if(arr[l] == ans1){
            l++;
            ans1++;
            rest--;
        }
        else{
            if(arr[r]-ans1>ans1){
               r--;
               ans1++;
               rest--;
            }
            else {
                l++;
                rest--;
            }
            
        }
    }
    int ans2 = 0;
     r =n-1;
     l =0;
     rest =n;
    while(rest>0){
        if(arr[l] == ans2){
            l++;
            ans2++;
            rest--;
        }
        else{
            if(arr[r]-ans2>ans2){
               r--;
               ans2++;
               rest--;
            }
            else {
                l++;
                rest--;
            }
            
        }
    }

    int ans3 = 0;
     r =n-1;
     l =0;
     rest =n;
    while(rest>0){
        if(arr[r]-ans3>ans3){
            r--;
            ans3++;
            rest--;
        }
        else{
            if(arr[l] == ans3){
                l++;
            ans3++;
            rest--;
               
            }
            else {
                r--;
                rest--;
            }
            
        }
    }
    int ans4 = 0;
     r =n-1;
     l =0;
     rest =n;
    while(rest>0){
        if(arr[r]-ans4>ans4){
            r--;
            ans4++;
            rest--;
        }
        else{
            if(arr[l] == ans4){
                l++;
            ans4++;
            rest--;
               
            }
            else {
                l++;
                rest--;
            }
            
        }
    }

    int ans = max(ans1,max(ans2,max(ans3,ans4)));
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}