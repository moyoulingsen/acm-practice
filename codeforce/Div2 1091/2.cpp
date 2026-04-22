#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    int n,m;
    cin>>n>>m;

    vector<int> a(n);

    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    
    

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

// **B. 翻转比特（简单版）**  
// 时间限制：每个测试 1.5 秒  
// 内存限制：256 MB  

// 这是该问题的简单版本。两个版本的区别在于，本版本中恰好只有一个特殊索引（\(k=1\)）。只有当你解决了该问题的所有版本后，才能进行 hack。

// 给定一个长度为 \(n\) 的二进制数组 \(a\) 和 \(k\) 个特殊索引 \(p_1, p_2, \dots, p_k\)（\(1 \le p_i \le n\)）。题目保证所有特殊索引处的元素值 \(a_i\) 均相同（即 \(a_{p_1} = a_{p_2} = \dots = a_{p_k}\)）。

// 在一次操作中，你可以选择一个区间 \([l, r]\)（\(1 \le l \le r \le n\)），要求该区间包含至少一个特殊索引（即存在 \(l \le p_i \le r\)），并将所有满足 \(l \le j \le r\) 的比特 \(a_j\) 进行翻转。翻转一个比特会将 \(0\) 变为 \(1\)，将 \(1\) 变为 \(0\)。

// 令 \(x\) 表示进行任何操作之前特殊索引处的值。求使数组所有元素均等于 \(x\) 所需的最少操作次数。

// **输入格式**  
// 每个测试包含多个测试用例。第一行包含测试用例数 \(t\)（\(1 \le t \le 10^4\)）。接下来是每个测试用例的描述。

// 每个测试用例的第一行包含两个整数 \(n\) 和 \(k\)（\(1 \le n \le 2 \cdot 10^5\)；\(k = 1\)）——数组长度与特殊索引的个数。

// 第二行包含 \(n\) 个整数 \(a_1, a_2, \dots, a_n\)（\(0 \le a_i \le 1\)）——数组的元素。

// 第三行包含 \(k\) 个整数 \(p_1, p_2, \dots, p_k\)（\(1 \le p_1 < p_2 < \dots < p_k \le n\)）——特殊索引。题目保证 \(a_{p_1} = a_{p_2} = \dots = a_{p_k}\)。

// 保证所有测试用例的 \(n\) 之和不超过 \(2 \cdot 10^5\)。

// **输出格式**  
// 对于每个测试用例，输出一个整数——所需的最少操作次数。