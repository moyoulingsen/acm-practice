#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<pair<int,double>> arr(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr[i].first = i;arr[i].second = a;
    } 

    sort(arr.begin(),arr.end(),[](auto a,auto b){
        if(a.second!=b.second)return a.second<b.second;
        return a.first<b.first; 
    });
    double sum =0;
    for(int i =0;i<n;i++){
        cout <<arr[i].first+1<<" ";
        sum += arr[i].second*(n-i-1);
    }
    cout<<"\n"<< fixed << setprecision(2)<< (sum/n);
    return 0;
}