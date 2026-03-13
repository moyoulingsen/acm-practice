#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n;
    cin>>m;
    struct h{int a;int b;int c;};//成员变量用；
    vector<h> arr;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        // h 是一个类型名（结构体标签），不是对象（变量）。不能通过 h.a 访问成员，因为 a 是结构体类型的成员，必须通过具体对象才能访问。
        // 正确的做法应该是先定义局部变量（如 int a, b, c;），然后从 cin 读取值到这些变量，最后用它们构造 h 对象。
        arr.push_back({a,b,c});
    }


    sort (arr.begin(),arr.end(),[](auto n,auto m){
        if(n.b!=m.b)return n.b<m.b;
        else return n.a<m.a; 
    });

    vector<int> tree(n+1);
    
    for(int i =0;i<m;i++){
        int cnt = 0;//这里初始化妙啊
        for(int pos = arr[i].a;pos <= arr[i].b;pos++){
            if(tree[pos]) cnt++;
        }

        if(cnt >=arr[i].c) {continue;}

        //有continue了之后就不需要else了

        //小心，在for里面一定要是常数，不可以变幻
        int need = arr[i].c - cnt;
        for(int pos/*注意for里面重复没有关系*/ = arr[i].b; pos>= arr[i].a&&need>0;pos-- ){
            if(!tree[pos]){
                tree[pos] = 1;
                need--;
            }
        }
        
    }
    int ans = 0;//初始化瑶赋值！！！
    for(int i = 0;i<=n;i++){
        if(tree[i]) ans ++;
    }
     cout << ans;
        




    

    return 0;
}