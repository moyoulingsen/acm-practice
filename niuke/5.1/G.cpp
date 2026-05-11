#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    rep(i,0,n){
        cin>>arr[i];
    }

    int l,r,ans=INT_FAST8_MAX;
    l=0;
    r=0;
    int a,b,c;
    a=1;
    b=1;
    c=1;
    queue<int> q;

    while(l<n&&r<n){
        if(arr[r]==4){
            q.push(4);
            m--;
            while(m==0&&a<1&&b<1&&c<1){
                ans = min(ans,r-l+1);
                int pre = arr[l];
                q.pop();
                l++;
                if(pre == 1){
                    a++;
                }
                if(pre == 2){
                    b++;
                }
                if(pre == 3){
                    c++;
                }
                if(pre == 4){
                    m++;
                }
            }
            r++;
        }
        else{
            q.push(arr[r]);
            if(arr[r]==1){
                a--;
            }
            if(arr[r]==2){
                b--;
            }
            if(arr[r]==3){
                c--;
            }
            r++;
        }
    }

    if(l<n){
        while(m==0&&a<1&&b<1&&c<1){
                ans = min(ans,r-l+1);
                int pre = arr[l];
                q.pop();
                l++;
                if(pre == 1){
                    a++;
                }
                if(pre == 2){
                    b++;
                }
                if(pre == 3){
                    c++;
                }
                if(pre == 4){
                    m++;
                }
            }
    }
    cout<<ans;
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