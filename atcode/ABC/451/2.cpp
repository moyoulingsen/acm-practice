#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    vector<int> arr(n+1);
    for(int i =0 ;i<n;i++){
        int x,y;
        cin>>x>>y;

        arr[x]--;
        arr[y]++;
    }
    for(int i =1 ;i<=m;i++){
        cout<<arr[i]<<"\n";
    }

    return 0;
}