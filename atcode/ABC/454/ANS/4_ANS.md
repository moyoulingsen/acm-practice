# D - (xx) Editorial by en_translator
This problem can be solved with the idea of canonical form.

For a string $S$ consisting of `(`, `x`, and `)`, define its canonical form $f(S)$ as:

the string resulting form repeatedly replacing any substring `(xx)` of $S$ into `xx` as many times as possible.
Then $f(S)$ is uniquely determined regardless of operations.

**(Proof)** (It may be a bit difficult. You may skip this.)

We prove it by induction. We assume the uniqueness of the canonical form of a string of length $(k-1)$ or less, and will prove the uniqueness of the canonical form a string of length $k$.

Suppose that there are $m$ occurrences of `(xx)` in a length-$k$ string $S$. Obviously, `(xx)` are all disjoint. We consider cases where $m=0,1$, and others separately.

- If $m=0$: the canonical form of $S$ is $S$ itself.
- If $m=1$: the canonical form of $S$ is obtained by replacing the unique occurrence of `(xx)` with `xx` in $S$. After the replacement, $S$ has a length $(k-2)$, whose canonical form is guaranteed unique by assumption.
- If $m\ge2$: Take two occurrences of `(xx)` in $S$, and call them $a$ and $b$. Note that replacing $a$ with `xx` does not affect to the existence of $b$ (and vice versa).

Let $S_a$ be the string obtained by replacing $a$ with `xx` in $S$. Since $S_a$ has a length $k-2$, by the inductive assumption the canonical form of $S_a$ equals the canonical form of the string obtained by replacing $b$ with `xx` in $S_a$.

Meanwhile, let $S_b$ be the string obtained by replacing $b$ with `xx` in $S$. Since $S_b$ has a length $k-2$, by the inductive assumption the canonical form of $S_b$ equals the canonical form of the string obtained by replacing $a$ with `xx` in $S_b$.

Here, the string obtained by replacing $b$ with `xx` in $S_a$ coincides with the string obtained by replacing $a$ with `xx` in $S_b$. Therefore, the canonical forms of $S_a$ and $S_b$ are equal. Since this discussion can be applied to any choice of $a$ and $b$, it turns out that replacing any occurrence of `(xx)` in $S$ with `xx` first ends up in an unique canonical form.

This concludes the proof. **(End of proof)**

---

We have shown the uniqueness of the canonical form a string $S$. We further has the following fact:

The following are equivalent:
1. Once can repeatedly perform the operations in the problem statement against string $A$ to make $A$ equal to $B$.
2. $f(A)=f(B)$.

**(Proof)** (It may be a bit difficult. You may skip this.)

**(2) → (1)**: Take any operation sequence $v$ that transforms $A$ into $f(A)$, and any operation sequence $w$ that transforms $B$ into $f(B)$.
By applying operation according to the operation sequence $v$ on $A$, it turns to $f(A)$. Then, by applying the reverse actions according to the operation sequence $w$, that is, replacing `xx` with `(xx)`, we can transform $f(A)=f(B)$ into $B$.

**(1) → (2)**: For any string $S$, let

$S'$ be the string obtained by replacing an occurrence of `xx` as a substring of $S$ with `(xx)`, and
$S''$ be the string obtained by replacing an occurrence of `(xx)` as a substring of $S$ with `xx`.

By the uniqueness of a canonical form, if $S'$ and $S''$ exist, then $f(S)=f(S')$ and $f(S)=f(S'')$ hold. This implies that a canonical form is invariant by an operation, which means if (1) holds, $f(A)=f(B)$ must hold.

**(End of proof)**

---

By these facts, it turns out that the problem can be solved by finding the canonical form $f(A)$ of a string $A$.

$f(A)$ can be computed using a stack. Specifically, the following algorithm yields the canonical form $f(A)$:

1. Prepare an empty string $C$.
2. For $i=1,2,\dots,|A|$ in order, perform the following:
   - Append $A_i$ to the end of $C$.
   - If the last four characters of $C$ are `(xx)`, replace it with `xx`.
3. The resulting string $C$ is $f(A)$.

This algorithm runs in $O(|A|)$ time. Therefore, the problem can be solved in a total of $O(|A|+|B|)$ time, which is fast enough.

---

## Sample code (C++)
```cpp
#include <iostream>
#include <string>
using namespace std;

string canonical_form(const string& S) {
  string T;
  for (auto& c : S) {
    T.push_back(c);
    if ((int)T.size() >= 4 and T.substr(T.size() - 4, 4) == "(xx)") {
      T.erase(end(T) - 4, end(T));
      T += "xx";
    }
  }
  return T;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    string A, B;
    cin >> A >> B;
    cout << (canonical_form(A) == canonical_form(B) ? "Yes" : "No") << "\n";
  }
}
```

# D - (xx) 题解
作者：en_translator

本题可以借助**标准型（canonical form）**的思想求解。

对于由 `(`、`x`、`)` 组成的字符串 $S$，定义其**标准型 $f(S)$** 为：
将 $S$ 中所有形如 `(xx)` 的子串**反复替换**为 `xx`，直到无法再替换为止，最终得到的字符串。
无论替换顺序如何，$f(S)$ 的结果都是唯一的。

---

### 证明（过程稍有难度，可跳过）
我们采用**数学归纳法**证明。假设长度不超过 $k-1$ 的字符串，其标准型具有唯一性，下面证明长度为 $k$ 的字符串的标准型也唯一。

设长度为 $k$ 的字符串 $S$ 中存在 $m$ 个 `(xx)` 子串。显然，这些 `(xx)` 子串彼此**互不重叠**。我们分三种情况讨论：
1. 若 $m=0$：$S$ 的标准型就是 $S$ 本身；
2. 若 $m=1$：将 $S$ 中唯一的 `(xx)` 替换为 `xx` 后，得到长度为 $k-2$ 的字符串，根据归纳假设，该字符串的标准型唯一；
3. 若 $m\ge2$：任取 $S$ 中的两个 `(xx)` 子串，记为 $a$ 和 $b$。注意：替换 $a$ 为 `xx` 不会影响 $b$ 的存在（反之亦然）。

设 $S_a$ 是将 $a$ 替换为 `xx` 后得到的字符串。由于 $S_a$ 长度为 $k-2$，根据归纳假设：
$S_a$ 的标准型 = 先替换 $S_a$ 中的 $b$ 得到的字符串的标准型。

同理，设 $S_b$ 是将 $b$ 替换为 `xx` 后得到的字符串。由于 $S_b$ 长度为 $k-2$，根据归纳假设：
$S_b$ 的标准型 = 先替换 $S_b$ 中的 $a$ 得到的字符串的标准型。

此时，「先替换 $S$ 中的 $a$、再替换 $b$」得到的字符串，与「先替换 $S$ 中的 $b$、再替换 $a$」得到的字符串完全相同。因此 $S_a$ 和 $S_b$ 的标准型相等。

由于该结论对任意选取的 $a$、$b$ 都成立，这说明：无论先替换 $S$ 中的哪一个 `(xx)` 子串，最终得到的标准型都是唯一的。

证明完毕。

---

我们已经证明了字符串 $S$ 的标准型的唯一性，此外还有以下核心结论：

以下两个命题**等价**：
1. 对字符串 $A$ 反复执行题目所述操作，可将 $A$ 变为 $B$；
2. $f(A) = f(B)$。

### 证明（过程稍有难度，可跳过）
- **(2) → (1)**：任取将 $A$ 转化为 $f(A)$ 的操作序列 $v$，以及将 $B$ 转化为 $f(B)$ 的操作序列 $w$。
  先对 $A$ 执行操作序列 $v$，$A$ 会变为 $f(A)$；再**逆序执行**操作序列 $w$（即把 `xx` 替换回 `(xx)`），就能将 $f(A)=f(B)$ 转化为 $B$。

- **(1) → (2)**：对任意字符串 $S$，定义：
  $S'$ = 将 $S$ 中某个 `xx` 子串替换为 `(xx)` 得到的字符串；
  $S''$ = 将 $S$ 中某个 `(xx)` 子串替换为 `xx` 得到的字符串。

  根据标准型的唯一性，若 $S'$ 和 $S''$ 存在，则 $f(S) = f(S')$ 且 $f(S) = f(S'')$ 恒成立。
  这说明**标准型在操作下保持不变**，因此若命题(1)成立，则必有 $f(A)=f(B)$。

证明完毕。

---

基于上述结论，本题的解法为：**分别计算两个字符串的标准型，判断是否相等即可**。

计算标准型 $f(A)$ 可以用**栈**高效实现，算法步骤如下：
1. 初始化一个空字符串 $C$；
2. 依次遍历 $A$ 的每一个字符：
   - 将当前字符追加到 $C$ 的末尾；
   - 若 $C$ 的最后四个字符是 `(xx)`，则将这四个字符替换为 `xx`；
3. 遍历结束后，$C$ 就是 $A$ 的标准型 $f(A)$。

该算法的时间复杂度为 $O(|A|)$，整体解法的时间复杂度为 $O(|A|+|B|)$，效率完全满足题目要求。

---

### 示例代码（C++）
```cpp
#include <iostream>
#include <string>
using namespace std;

// 计算字符串的标准型
string canonical_form(const string& S) {
  string T;
  for (auto& c : S) {
    T.push_back(c);
    // 若末尾4个字符是 (xx)，则替换为 xx
    if ((int)T.size() >= 4 && T.substr(T.size() - 4, 4) == "(xx)") {
      T.erase(end(T) - 4, end(T));
      T += "xx";
    }
  }
  return T;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    string A, B;
    cin >> A >> B;
    // 比较标准型，相等则输出Yes，否则No
    cout << (canonical_form(A) == canonical_form(B) ? "Yes" : "No") << "\n";
  }
}
```

---

### 总结
1. 核心思路：将字符串转化为**唯一的标准型**，通过比较标准型判断两个字符串是否可互转；
2. 实现方法：用字符串模拟栈，遍历过程中实时替换末尾的 `(xx)` 为 `xx`；
3. 时间复杂度：线性时间，高效处理输入。