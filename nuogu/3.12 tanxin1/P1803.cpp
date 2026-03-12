#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;

    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.emplace_back(a,b);//你看看这种，如果vector（n）那就默认前面n赋值0
                              //push——back那就vector什么都没有空着就可以
    }

    sort(arr.begin(),arr.end(),[](auto a,auto b){
        if(a.second!=b.second) return a.second<b.second;//second不是成员函数，（）不需要
        return a.first<b.first;
    });//排序后面有结束

    int cur = arr[0].second;
    int ans = 1;//答案少一多一，这里是不是漏数了
    for(int i=0;i<n;i++){
        if(arr[i].first>= cur ) {cur = arr[i].second;ans++;
    }}

    cout << ans;
    //明明声明了还有报错，很有可能前面漏分号了
    return 0;
}