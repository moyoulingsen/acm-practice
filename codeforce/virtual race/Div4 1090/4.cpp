#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    int n;cin>>n;
    vector <int> prime(1000000);
    for(int i = 2;i*i<1000000;i++){
        if(!prime[i]){
            for(int j = i*i;j<1000000;j+=i){
                prime [j] = 1; 
            }
        }
    } 
    int prev = 1;
    int num = 0;
    for(int i = 2;i<1000000;i++){
        if(num == n){
            cout<<endl;
            break;
        }
        if(!prime[i]){
            
            prime [i] = 1;
            cout <<  prev*i<<" ";
            prev = i;
            num++;
        }
    }


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