# 英文原题解（Markdown）
## C - Understory Editorial by en_translator
### Overview of Problem
This problem is an exercise of a data structure called Priority Queue (Heap). This is implemented as `heapq` in Python, or `priority_queue` in C++.

### Notes: Max- and Min- Heap
`heapq` in Python is a min-heap, which maintains the “minimum value” by default; meanwhile, `priority_queue` in C++ is a max-heap, which maintains the “maximum value” by default.

Thus, when we want to take out smaller values first in C++ (as in this problem), we need the following type arguments on declaration:
```cpp
priority_queue<int, vector<int>, greater<int>> que;
```

### What Heap Can Do
While detailed methods and complexity vary depending on implementation, a heap roughly supports the following operations. Let $N$ be the number of elements in the heap when an operation is performed.

1. **Retrieve the minimum value**
Retrieves the minimum value in the heap (without removing).
Complexity: $O(1)$
Python: `que[0]`
C++: `que.top()`

2. **Take out the minimum value**
Removes the minimum value in the heap.
Complexity: $O(\log N)$
Python: `heappop(que)`
C++: `que.pop()`

3. **Insert an element**
Inserts an element into the heap.
Complexity $O(\log N)$
Python: `heappush(que, x)`
C++: `que.push(x)`

### Implementation
In case of our problem, the problem can be solved by implementing a simulation that performs:
- **Type 1**
  Insert $h$ to the heap.
- **Type 2**
  Retrieve the minimum value, and remove it if it is $h$ or less. Repeat it until it is not $h$ or less.

This can be implemented as follows:

#### Implementation in Python
```python
from heapq import heappop, heappush
que = []
q = int(input())
for i in range(q):
    t, h = map(int, input().split())
    if t == 1:
        heappush(que, h)
    else:
        while que and que[0] <= h:
            heappop(que)
    print(len(que))
```

#### Implementation in C++
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int q; cin >> q;
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i=0; i<q; i++){
        int t, h; cin >> t >> h;
        if (t == 1){
            que.push(h);
        }else{
            while(!que.empty() and que.top() <= h){
                que.pop();
            }
        }
        cout << que.size() << endl;
    }
}
```

### Complexity
The complexity can be analyzed as follows.

- **Insertion**
  This occurs once per one type-1 query, for a total of $O(N)$ times.

- **Removal**
  One may feel that computational complexity may bloat up because we may remove many elements in a type-2 query.
  However, once an element is removed, it cannot be removed again, so “the number of removals” must be not greater than “the number of insertions.” Thus, it occurs a total of $O(N)$ times.

- **Retrieval of minimum value**
  It is almost the same as the number of removals. In a type-2 query, there may be an element that is referenced as the minimum value, but not removed.
  However, such an element exists at most one per a query, so the number of occurrences is at most $Q$ times more than the removal count. Thus, it is bounded by $O(Q)$.

Hence, the complexity is $O(Q\log Q)$.

---

# 中文翻译（Markdown）
## C - Understory 题解 by en_translator
### 题目概述
本题是对**优先队列（堆）**这一数据结构的练习。在 Python 中通过 `heapq` 模块实现，在 C++ 中通过 `priority_queue` 实现。

### 注意：大根堆与小根堆
Python 的 `heapq` 默认是**小根堆**，会维护堆中的最小值；而 C++ 的 `priority_queue` 默认是**大根堆**，会维护堆中的最大值。

因此，在 C++ 中需要优先取出较小值时（和本题需求一致），需要按如下方式声明优先队列：
```cpp
priority_queue<int, vector<int>, greater<int>> que;
```

### 堆的核心操作
不同编程语言的实现细节和复杂度略有差异，堆大致支持以下三种操作（设操作时堆内元素数量为 $N$）：

1. **获取堆顶最小值**
   读取堆中的最小值（不删除元素）。
   时间复杂度：$O(1)$
   Python：`que[0]`
   C++：`que.top()`

2. **弹出堆顶最小值**
   删除堆中的最小值。
   时间复杂度：$O(\log N)$
   Python：`heappop(que)`
   C++：`que.pop()`

3. **插入元素**
   向堆中添加一个新元素。
   时间复杂度：$O(\log N)$
   Python：`heappush(que, x)`
   C++：`que.push(x)`

### 实现思路
针对本题，我们只需模拟以下操作即可解决问题：
- **操作 1**
  将数值 $h$ 插入堆中。
- **操作 2**
  取出堆顶最小值，若该值小于等于 $h$ 则删除；重复此操作，直到堆顶最小值大于 $h$。

具体实现代码如下：

#### Python 实现
```python
from heapq import heappop, heappush
que = []
q = int(input())
for i in range(q):
    t, h = map(int, input().split())
    if t == 1:
        heappush(que, h)
    else:
        while que and que[0] <= h:
            heappop(que)
    print(len(que))
```

#### C++ 实现
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int q; cin >> q;
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i=0; i<q; i++){
        int t, h; cin >> t >> h;
        if (t == 1){
            que.push(h);
        }else{
            while(!que.empty() and que.top() <= h){
                que.pop();
            }
        }
        cout << que.size() << endl;
    }
}
```

### 复杂度分析
复杂度分析如下：
- **插入操作**
  每个操作 1 执行一次插入，总次数为 $O(N)$。

- **删除操作**
  你可能会担心单次操作 2 批量删除元素导致复杂度超标，但每个元素最多被删除一次，总删除次数不会超过总插入次数，因此总次数为 $O(N)$。

- **获取最小值**    
  次数与删除操作基本一致。单次操作 2 中可能存在仅读取堆顶但不删除的情况，但每个查询最多出现一次，因此总次数仅比删除操作多 $Q$ 次，复杂度被限制在 $O(Q)$。

综上，整体时间复杂度为 $O(Q\log Q)$。