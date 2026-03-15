#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h,w,q;
    cin>>h>>w>>q;

    while(q--){
        int n,m;
        cin>>n>>m;
        if(n==1){
            cout << m*w<<"\n";
            h-=m; 
        }
        if(n==2){
            cout<< m*h<<"\n";
            w-=m;
        }
    }


    return 0;
}