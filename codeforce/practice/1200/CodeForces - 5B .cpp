#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    vector<string> arr;
    string s;               //////////////////////////////////这里必须声明
    while (getline(cin, s)) ///////////////////精髓1：getline（cin，s）
        arr.push_back(s);
    int mmax = 0;
    for (auto v : arr)
    {
        mmax = max(mmax, (long long)v.size()); // max必须是同类型
    }

    rep(i, 0, mmax + 2)
    {
        cout << "*";
    }
    cout << endl; // cout还会拼写错误

    int cha = 0;
    for (auto str : arr)
    {
        int rest = mmax - str.size();
        int l, r;
        if (rest % 2 == 0)
        {
            l = rest / 2;
            r = rest / 2;
        }
        else
        {
            if (cha)
            {
                r = rest / 2;
                l = rest - r;
            }
            else
            {
                l = rest / 2;
                r = rest - l;
            }
            cha ^= 1;
        }
        cout << "*" << string(l, ' ') << str << string(r, ' ') << "*\n"; ///////////精髓2：string(7,' '),构造字符串
    }

    rep(i, 0, mmax + 2)
    {
        cout << "*";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}

// Almost every text editor has a built-in function of center text alignment. The developers of the popular in Berland text editor «Textpad» decided to introduce this functionality into the fourth release of the product.

// You are to implement the alignment in the shortest possible time. Good luck!

// Input
// The input file consists of one or more lines, each of the lines contains Latin letters, digits and/or spaces. The lines cannot start or end with a space. It is guaranteed that at least one of the lines has positive length. The length of each line and the total amount of the lines do not exceed 1000.

// Output
// Format the given text, aligning it center. Frame the whole text with characters «*» of the minimum size. If a line cannot be aligned perfectly (for example, the line has even length, while the width of the block is uneven), you should place such lines rounding down the distance to the left or to the right edge and bringing them closer left or right alternatively (you should start with bringing left). Study the sample tests carefully to understand the output format better.

// Examples
// Input复制	Output复制
// This  is

// Codeforces
// Beta
// Round
// 5
// ************
// * This  is *
// *          *
// *Codeforces*
// *   Beta   *
// *  Round   *
// *     5    *
// ************
// Input复制	Output复制
// welcome to the
// Codeforces
// Beta
// Round 5

// and
// good luck
// ****************
// *welcome to the*
// *  Codeforces  *
// *     Beta     *
// *   Round 5    *
// *              *
// *      and     *
// *  good luck   *
// ****************

// 几乎所有文本编辑器都内置了文本居中对齐的功能。流行的 Berland 文本编辑器 «Textpad» 的开发者决定在该产品的第四个版本中引入这一功能。

// 你需要在尽可能短的时间内实现该对齐功能。祝你好运！

// **输入**
// 输入文件包含一行或多行，每行由拉丁字母、数字和/或空格组成。每行不能以空格开头或结尾。保证至少有一行的长度为正数。每行的长度以及总行数均不超过 1000。

// **输出**
// 对给定文本进行格式化，使其居中对齐。用字符 «*» 将整个文本块框起来，且边框尺寸尽可能小。如果某一行无法完美居中对齐（例如，该行长度为偶数，而文本块的宽度为奇数），则应将此类行到左边距或右边距的距离向下取整，并交替地使其偏左或偏右（应从偏左开始）。请仔细研究样例测试以更好地理解输出格式。

// **样例**

// 输入样例复制
// ```
// This  is

// Codeforces
// Beta
// Round
// 5
// ```

// 输出样例复制
// ```
// ************
// * This  is *
// *          *
// *Codeforces*
// *   Beta   *
// *  Round   *
// *     5    *
// ************
// ```

// 输入样例复制
// ```
// welcome to the
// Codeforces
// Beta
// Round 5

// and
// good luck
// ```

// 输出样例复制
// ```
// ****************
// *welcome to the*
// *  Codeforces  *
// *     Beta     *
// *   Round 5    *
// *              *
// *      and     *
// *  good luck   *
// ****************
// ```