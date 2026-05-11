**题解翻译**

直接按照题目描述朴素地拼接数组可能会导致超时或超出内存限制，因此我们需要寻找其他方法。

我们需要确定 \( K \) 对应的是哪个序列 \( A_i \) 中的哪个元素。

通过逐步模拟构造过程，可以发现，答案是满足 \(\sum_{j=1}^{k-1} L_j C_j < K\) 的最大 \( k \) 所对应的序列 \( A_k \) 中的元素。
**题解翻译**

直接按照题目描述朴素地拼接数组可能会导致超时或超出内存限制，因此我们需要寻找其他方法。

我们需要确定 \( K \) 对应的是哪个序列 \( A_i \) 中的哪个元素。

通过逐步模拟构造过程，可以发现，答案是满足 \(\sum_{j=1}^{k-1} L_j C_j < K\) 的最大 \( k \) 所对应的序列 \( A_k \) 中的元素。

因此，可以按以下步骤求解：

对于 \( i = 1, 2, \dots, N \) 顺序执行：
- 如果 \( K \le L**题解翻译**

直接按照题目描述朴素地拼接数组可能会导致超时或超出内存限制，因此我们需要寻找其他方法。

我们需要确定 \( K \) 对应的是哪个序列 \( A_i \) 中的哪个元素。

通过逐步模拟构造过程，可以发现，答案是满足 \(\sum_{j=1}^{k-1} L_j C_j < K\) 的最大 \( k \) 所对应的序列 \( A_k \) 中的元素。

因此，可以按以下步骤求解：

对于 \( i = 1, 2, \dots, N \) 顺序执行：
- 如果 \( K \le L_i \times C_i \)，那么所求即为将 \( A_i \) 重复 \( C_i \) 次后的第 \( K \) 个元素，也就是 \( A_{i, (K-1) \bmod L_i + 1} \)。
- 否则，将 \( K \) 替换为 \( K - L_i \times C_i \)。

直接实现上述算法即可解决本题。

---

**C++ 实现**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;
    K--; // 转为 0 基索引，方便取模

    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        A[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N; i++) {
        long long len = (long long)C[i] * A[i].size();
        if (K < len) {
            cout << A[i][K % A[i].size()] << "\n";
            break;
        }
        K -= len;
    }

    return 0;
}
```_i \times C_i \)，那么所求即为将 \( A_i \) 重复 \( C_i \) 次后的第 \( K \) 个元素，也就是 \( A_{i, (K-1) \bmod L_i + 1} \)。
- 否则，将 \( K \) 替换为 \( K - L_i \times C_i \)。

直接实现上述算法即可解决本题。

---

**C++ 实现**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;
    K--; // 转为 0 基索引，方便取模

    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        A[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N; i++) {
        long long len = (long long)C[i] * A[i].size();
        if (K < len) {
            cout << A[i][K % A[i].size()] << "\n";
            break;
        }
        K -= len;
    }

    return 0;
}
```
因此，可以按以下步骤求解：

对于 \(**题解翻译**

直接按照题目描述朴素地拼接数组可能会导致超时或超出内存限制，因此我们需要寻找其他方法。

我们需要确定 \( K \) 对应的是哪个序列 \( A_i \) 中的哪个元素。

通过逐步模拟构造过程，可以发现，答案是满足 \(\sum_{j=1}^{k-1} L_j C_j < K\) 的最大 \( k \) 所对应的序列 \( A_k \) 中的元素。

因此，可以按以下步骤求解：

对于 \( i = 1, 2, \dots, N \) 顺序执行：
- 如果 \( K \le L_i \times C_i \)，那么所求即为将 \( A_i \) 重复 \( C_i \) 次后的第 \( K \) 个元素，也就是 \( A_{i, (K-1) \bmod L_i + 1} \)。
- 否则，将 \( K \) 替换为 \( K - L_i \times C_i \)。

直接实现上述算法即可解决本题。

---

**C++ 实现**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;
    K--; // 转为 0 基索引，方便取模

    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        A[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N; i++) {
        long long len = (long long)C[i] * A[i].size();
        if (K < len) {
            cout << A[i][K % A[i].size()] << "\n";
            break;
        }
        K -= len;
    }

    return 0;
}
``` i = 1, 2, \dots, N \) 顺序执行：
- 如果 \( K \le L_i \times C_i \)，那么所求即为将 \( A_i \) 重复 \( C_i \) 次后的第 \( K \) 个元素，也就是 \( A_{i, (K-1) \bmod L_i + 1} \)。
- 否则，将 \( K \) 替换为 \( K - L_**题解翻译**

直接按照题目描述朴素地拼接数组可能会导致超时或超出内存限制，因此我们需要寻找其他方法。

我们需要确定 \( K \) 对应的是哪个序列 \( A_i \) 中的哪个元素。

通过逐步模拟构造过程，可以发现，答案是满足 \(\sum_{j=1}^{k-1} L_j C_j < K\) 的最大 \( k \) 所对应的序列 \( A_k \) 中的元素。

因此，可以按以下步骤求解：

对于 \( i = 1, 2, \dots, N \) 顺序执行：
- 如果 \( K \le L_i \times C_i \)，那么所求即为将 \( A_i \) 重复 \( C_i \) 次后的第 \( K \) 个元素，也就是 \( A_{i, (K-1) \bmod L_i + 1} \)。
- 否则，将 \( K \) 替换为 \( K - L_i \times C_i \)。

直接实现上述算法即可解决本题。

---

**C++ 实现**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;
    K--; // 转为 0 基索引，方便取模

    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        A[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N; i++) {
        long long len = (long long)C[i] * A[i].size();
        if (K < len) {
            cout << A[i][K % A[i].size()] << "\n";
            break;
        }
        K -= len;
    }

    return 0;
}
```i \times C_i \)。

直接实现上述算法即可解决本题。

---

**C++ 实现**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;
    K--; // 转为 0 基索引，方便取模

    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        A[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N; i++) {
        long long len = (long long)C[i] * A[i].size();
        if (K < len) {
            cout << A[i][K % A[i].size()] << "\n";
            break;
        }
        K -= len;
    }

    return 0;
}
```