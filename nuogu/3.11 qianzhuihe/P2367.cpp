#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,p;
    cin >>n>>p;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>> a[i];
    }
    
    vector<int> d(n+2);
    a[0]=0;
    for(int i =1;i<=n;i++){
        d[i] =a[i]-a[i-1];
    }

    while(p--){
        int x,y,z;
        cin>>x>>y>>z;
        d[x]+=z;
        d[y+1]-=z;

        

    
    }
    for(int i=1;i<=n;i++){
            a[i] =a[i-1]+d[i];
        }//这里不提出来，相当于没有提啊
    auto it = min_element(a.begin()+1,a.end());
        cout << *it;
    
    return 0;
}