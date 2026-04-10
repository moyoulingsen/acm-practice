#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    vector<int> prime(10000,1);
    prime[0]=prime[1] = 0;
    for(int i = 2;i*i<10000;i++){
        if(prime[i]){
            for(int j = i*i;j<10000;j+=i){
                prime[j]=0;
            }
        }
    }

    int n,m;
    cin>>n>>m;
    
    vector<int> vis(10000);
    queue<int> q;

    q.push(n);
    vis[n] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == m) {vis[m]=vis[cur];break;}

        for(int i = 1;i<=9;i++){
            int num = cur % 1000+i*1000;
            if (prime[num] && vis[num] == 0){
                vis[num] = vis[cur]+1;
                q.push(num);
            }
        }
        for(int i = 0;i<=9;i++){
            int num = cur % 100+i*100+(cur/1000)*1000;
            if (prime[num] && vis[num] == 0){
                vis[num] = vis[cur]+1;
                q.push(num);
            }
        }
        for(int i = 0;i<=9;i++){
            int num = cur % 10+i*10+(cur/100) *100;
            if (prime[num] && vis[num] == 0){
                vis[num] = vis[cur]+1;
                q.push(num);
            }
        }
        for(int i = 0;i<=9;i++){
            int num = (cur/10)*10+i;
            if (prime[num] && vis[num] == 0){
                vis[num] = vis[cur]+1;
                q.push(num);
            }
        }
    }
    cout << vis[m]-1<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}