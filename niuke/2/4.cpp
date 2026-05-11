#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int x,y,z;
    int n;cin>>n;
    vector<int> arr(n);
    int sum = 0;
    int ans = 1;
    set<int> s;
    rep(i,0,n){
        cin>>arr[i];
        s.insert(arr[i]);
        sum+=arr[i];
    }
    if(sum%n!=0){
        ans = 0;
    }

    if(s.size() == 3){
            
            auto a = s.begin();
            auto b = s.begin();
            auto c = s.rbegin();
         x = *a;
         y = *next(a);
         z = *c;
         if(arr[0]== y){
        rep(i,1,n-1){
            if(arr[i]==z){
                if(arr[i+1]==z){
                    ans = 0;
                    break;
                }
            }
            if(arr[i]==x){
                if(arr[i+1]==x){
                    ans =0;
                    break;
                }
            }
    }
    }

    else if(arr[0]==z){
        if(arr[n-1]==z){
            ans = 0;
        }
        rep(i,1,n-1){
            if(arr[i]==z){
                if(arr[i+1]==z){
                    ans = 0;
                    break;
                }
            }
            if(arr[i]==x){
                if(arr[i+1]==x){
                    ans =0;
                    break;
                }
            }
    }
    }
    
    else {
        if(arr[n-1]==x){
            ans = 0;
        }
        rep(i,1,n-1){
            if(arr[i]==z){
                if(arr[i+1]==z){
                    ans = 0;
                    break;
                }
            }
            if(arr[i]==x){
                if(arr[i+1]==x){
                    ans =0;
                    break;
                }
            }
    }
    }

}
else if(s.size()==2){
    auto a = s.begin();
            
            auto c = s.rbegin();
         x = *a;
         z = *c;

         if(z-x==2&&arr[0]!=arr[n-1]){
             rep(i,0,n-1){
                if(arr[i]==arr[i+1])ans = 0;
             }
         }
         else{
            ans = 0;
         }
         
         
}
else if(s.size()== 1 ){
    ans = 1;
}
else{
    ans = 0;
}

    


    

    
 
    
    
    cout<<((ans == 1)?"YES\n":"NO\n");



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