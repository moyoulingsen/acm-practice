#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K,M;
    cin>>N>>K>>M;
    vector<pair<int,int>> bs(N);
    for(auto&[v,c]:bs) cin>>c>>v;
    sort(bs.begin(),bs.end(),greater<>());
    ll sum=0;
    unordered_map<int,int>cnt;
    for(int i=0;i<K;++i)
    {
        //auto[v,c]=bs[i];
        //巧妙地v,c代替了bs[i].first;ns[i].second的写法
        auto[v,c]=bs[i];
        sum+=v;
        ++cnt[c];
    }
    //map<int,int> cnt
    //记录个数
    //++cnt[c]

    int dis=cnt.size();
    if(dis>=M)
    {
        cout<<sum<<'\n';
        return 0;
    }
    priority_queue<int,vector<int>,greater<>>hp;
    //大根堆priority_queue<int>
    //top()是大元素

    
    unordered_map<int,bool>kt;
    for(int i=0;i<K;++i)
    {
        auto[v,c]=bs[i];
        //auto[v,c]=bs[i];
        //巧妙地v,c代替了bs[i].first;ns[i].second的写法
        if(!kt[c])kt[c]=true;
        else hp.push(v);
        //没有用vector来计数，用map自然的加入计数
        //map<int,bool>
        //判断有没有标记过

//         判第一次出现
// unordered_map<int,bool> vis;
// if(!vis[x]) vis[x] = true;

// 2. 所以 if(!vis[x]) 是什么意思
// if(!vis[x])
// 分两种情况：

// 情况 A：x 从没出现过
// 比如当前 vis 还是空的。
// 执行：
// if(!vis[5])
// 发生的事是：
// vis[5] 不存在
// 自动插入 vis[5] = false
// !vis[5] 就是 !false
// 条件成立
// 于是进入 if：
// vis[5] = true;
// 现在就表示：5 出现过了。

// 情况 B：x 已经出现过
// 如果之前已经执行过：
// vis[5] = true;
// 那么再来：
// if(!vis[5])
// 此时：
// vis[5] 已经存在，值是 true
// !true 是 false
// 所以不会进入 if。
    }
    for(int i=K;i<N&&dis<M;++i)
    {
        //i<N&&dis<M这就是你梦寐以求的while
        //约束条件可以在while（）里面
        //也可以for（；；）里面
        //还可以是if（）break;里面
        auto[v,c]=bs[i];
        if(!kt[c])
        {
            sum+=v-hp.top();
            hp.pop();
            kt[c]=true;
            ++dis;
        }
    }
    cout<<sum<<'\n';
    return 0;
}