# 线下 ACM 短板子说明

目标：短、稳、快翻，不写冷门长模板。

## 1. 万能题头

建议直接用 [template.cpp](/C:/Users/ASUS/Desktop/acm-pracice/atcode/ABC/acm_board/template.cpp)。

原则：

- 默认不要 `#define int long long`
- 下标、点编号用 `int`
- 权值、答案、前缀和用 `long long`

## 2. STL 容器和常用语法

这些只记最常用写法，比赛够用：

```cpp
vector<int> a;
a.push_back(x);
a.pop_back();
sort(a.begin(), a.end());
reverse(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
lower_bound(a.begin(), a.end(), x);
upper_bound(a.begin(), a.end(), x);

set<int> s;
s.insert(x);
s.erase(x);
s.count(x);
s.find(x);

multiset<int> ms;
ms.insert(x);
ms.erase(ms.find(x)); // 只删一个

map<int, int> mp;
mp[x]++;
mp.count(x);
mp.erase(x);

multimap<int, int> mmp;
mmp.insert({k, v});

unordered_set<int> us;
us.insert(x);
us.count(x);

queue<int> q;
q.push(x); q.front(); q.pop();

deque<int> dq;
dq.push_front(x); dq.push_back(x);
dq.front(); dq.back();
dq.pop_front(); dq.pop_back();

stack<int> st;
st.push(x); st.top(); st.pop();

priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int>> mn;
```

顺手记住这些 `algorithm`：

```cpp
sort(a.begin(), a.end());
reverse(a.begin(), a.end());
*min_element(a.begin(), a.end());
*max_element(a.begin(), a.end());
accumulate(a.begin(), a.end(), 0LL);
count(a.begin(), a.end(), x);
binary_search(a.begin(), a.end(), x);
next_permutation(a.begin(), a.end());
```

## 3. 图论怎么选

- 无权最短路：`BFS`
- 普通遍历、连通块：`DFS`
- 图大怕爆栈：`迭代 DFS`
- 非负权最短路：`Dijkstra`
- 有负边：`Bellman-Ford / SPFA`
- 网格且有强估价函数：`A*`

说明：

- `A*` 不是常规主力，只有启发函数好写时才值得带
- 网格最短路多数题 `BFS` 就够了
- 负权边题比普通最短路少，板子带一个就行；这份代码放的是 `Bellman-Ford`，更稳

## 4. DFS 内存优化

递归 DFS 容易爆栈，线下赛更建议：

- 大图改手写 `stack`
- 邻接表尽量别开在函数局部大数组
- 数据特别大时再考虑前向星

## 5. 并查集

适用题型：

- 判断连通
- 动态合并集合
- 最小生成树 Kruskal
- 网格联通块

必会接口：

```cpp
find(x)
unite(a, b)
same(a, b)
size(x)
```

## 6. 链表

ACM 里 `std::list` 很少是最优选择，真要考链表操作，常用的是：

- 数组模拟单链表
- 数组模拟双链表

这份板子放的是双链表，适合：

- O(1) 插入
- O(1) 删除
- 按节点编号操作

## 7. 背包只记循环方向

最容易混的是循环方向：

- `01 背包`：`j` 从大到小
- `完全背包`：`j` 从小到大
- `多重背包`：二进制拆分后按 `01` 做
- `分组背包`：每组最多选一个
- `二维费用背包`：双维都从大到小

补充建议：

- 线下赛至少带 `01 / 完全 / 多重 / 分组`
- 如果纸面紧张，二维费用背包只记循环结构，不一定整段抄

## 8. 高精度怎么带

原则：用哪个抄哪个，不要全带满。

高频程度一般是：

1. 高精加
2. 高精减
3. 高精乘
4. 高精除以 `int`

说明：

- `高精除高精` 很少考，不建议占版面
- 这份代码里的减法默认 `a >= b`
- 除法给的是“高精 / int”，比赛里最常用

## 9. 数论

必须会：

- 快速幂
- `gcd / lcm`
- 扩展欧几里得
- 逆元
- 质数筛

斐蜀定理要记一句话就够：

`ax + by = gcd(a, b)` 有整数解。

逆元怎么选：

- `mod` 是质数：`a^(mod-2) mod mod`
- 一般情况且 `gcd(a, mod) = 1`：扩欧

## 10. 异或性质

板子上直接记这些：

- `a ^ a = 0`
- `a ^ 0 = a`
- 交换律、结合律成立
- 前缀异或和能做区间异或
- 一个数出现偶数次会被抵消

常见用途：

- 找只出现一次的数
- 状态压缩
- 构造题

## 11. 我建议你额外补上的板子

虽然你这次没点名，但线下赛非常高频：

- 二分答案
- 前缀和 / 差分
- 拓扑排序
- 树状数组

这些建议直接继续看 [snippets.cpp](/C:/Users/ASUS/Desktop/acm-pracice/atcode/ABC/acm_board/snippets.cpp)。

## 12. 真正带去现场的精简建议

如果页数很紧，只保留这些：

1. 万能题头
2. STL 容器速记
3. BFS / 迭代 DFS / Dijkstra / 并查集
4. 01 / 完全 / 多重 / 分组背包
5. 高精加减乘除 `int`
6. 快速幂 / exgcd / 逆元 / 质数筛 / 异或性质

`A*` 和链表优先级都不高，页数不够时先删它们。
