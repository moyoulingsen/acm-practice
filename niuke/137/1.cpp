#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    cout<<n/3600<<" "<<(n%3600)/60<<" "<<(n%3600)%60;

    return 0;
}