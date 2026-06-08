# A - Two Arithmetic Progressions 官方题解整理

- 题目链接：https://atcoder.jp/contests/arc221/tasks/arc221_a
- 官方题解链接：https://atcoder.jp/contests/arc221/editorial/21041
- 作者：evima

## 官方题解核心内容

官方给了两种做法。

---

## Solution 1

利用欧几里得算法，可以把问题化简到 `C = 0` 的情形。

```text
while C != 0:
    k = floor(A / C)
    A = A - k * C
    B = B - k * D
    swap(A, C)
    swap(B, D)
```

设变换后的值为 `A', B', C'(=0), D'`。
则原式可化为：

\[
\sum_{i=1}^{N} \gcd(A'i+B', |D'|)
\]

其中 `|D'| <= 10^8`，因为 `|AD - BC|` 在变换过程中保持不变。

### 当 `D' = 0`

此时问题可以直接计算。

### 当 `D' != 0`

对于 `D'` 的每个正因子 `m`：

- 统计有多少个 `i (1 <= i <= N)` 满足 `A'i + B'` 是 `m` 的倍数；
- 这个问题可以通过求解线性同余 / 线性丢番图方程完成；
- 再对所有因子做 Möbius 反演，就可以求出 `gcd(Ai+B, |D'|) = m` 的个数。

因为 `10^8` 以内整数的因子个数最多只有 `768`，所以即使对因子做二重枚举也足够快。

---

## Solution 2

注意恒等式：

\[
C(Ai+B) - A(Ci+D) = CB - AD
\]

因此：

\[
\gcd(Ai+B, Ci+D)
\]

一定是 `|CB - AD|` 的因子。

- 如果 `CB - AD = 0`，问题也能直接处理；
- 否则枚举 `|CB - AD|` 的每个因子 `m`；
- 统计同时满足 `Ai+B` 和 `Ci+D` 都是 `m` 的倍数的 `i` 的个数；
- 再像 Solution 1 一样做 Möbius 反演。

---

## 官方题解附带代码（Python）

```python
from atcoder.math import inv_mod
from math import gcd

def divisors(n):
    lower, upper = [], []
    i = 1
    while i * i <= n:
        if n % i == 0:
            lower.append(i)
            if i * i != n:
                upper.append(n // i)
        i += 1
    return lower + upper[::-1]

mod = 998244353

def solve():
    n, A, B, C, D = map(int, input().split())
    B += A
    D += C
    while C != 0:
        k = A // C
        A -= k * C
        B -= k * D
        A, B, C, D = C, D, A, B
    if D == 0:
        print((n * (n - 1) // 2 * A + B * n) % mod)
        return
    divs = divisors(abs(D))
    sz = len(divs)
    cnt = [0] * sz
    ans = 0
    for i in range(sz - 1, -1, -1):
        m = divs[i]
        g = gcd(A, m)
        if B % g == 0:
            p, q, r = A // g, B // g, m // g
            mn = (-q * inv_mod(p, r)) % r
            cnt[i] = max(0, (n - 1 - mn) // r + 1)
        for j in range(i + 1, sz):
            if divs[j] % m == 0:
                cnt[i] -= cnt[j]
        ans += m * cnt[i]
    print(ans % mod)

for _ in range(int(input())):
    solve()
```
