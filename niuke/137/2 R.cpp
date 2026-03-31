#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    int n;cin>>n;
    string s;cin>>s;

    deque<char> arr;/////////双向字符，而不是双向int
    bool d = 1;
    for(auto w:s){
        if(w>='a'&&w<='z'){
            if(d) arr.push_back(w);
            else arr.push_front(w);
        }
        else if(w== '!'){
            d^=1;
        }
        else{
            if(arr.empty()) continue;
            if(d)arr.pop_back();
            else arr. pop_front();
        }
    }

    if(arr.empty()){
        cout<<"Empty"<<endl;//小心拼写错误
    }
    else {
        for(int i =0;i<arr.size();i++){//这里小于大于号可不能乱写啊
            cout << arr[i];
        }
        cout << endl;
        ///////这里是最后才换行
        //     这里还可以写
        // for(auto w:arr)cout << w;
        // cout << endl;
    }
    
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