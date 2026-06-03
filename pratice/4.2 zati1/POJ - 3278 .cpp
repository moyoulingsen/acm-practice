#include <vector>
#include<queue>
#include<iostream>

using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

vector<int> vis(2*10e5+1,-1);



int bfs (int a,int b){
    queue<int> q;
        q.push(a);
        vis[a] = 0;

    while(!q.empty()){
        

        int cur = q.front();
        q.pop();
        vector <int> arr={1,-1,cur}; 

        if(cur == b){
            return vis[cur];
        }

        for(int i = 0;i<3;i++){
            int x = cur+arr[i];

            if(x <0||x>2*10e5){
                continue;
            }

            if(vis[x]!=-1)continue;

            q.push(x);
            vis[x] = vis[cur]+1; 
        }
    }
    return
}

void solve() {
    int a,b;
    cin>>a>>b;
    
    cout << bfs(a,b);
    
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