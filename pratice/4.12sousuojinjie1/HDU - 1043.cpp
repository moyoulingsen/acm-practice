#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    vector<vector<char>> grid(3,vector<char> (3));
    rep(i,0,3)rep(j,0,3)cin>>grid[i][j];

    
    
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
// The 15-puzzle has been around for over 100 years; even if you don't know it by that name, you've seen it. It is constructed with 15 sliding tiles, each with a number from 1 to 15 on it, and all packed into a 4 by 4 frame with one tile missing. Let's call the missing tile 'x'; the object of the puzzle is to arrange the tiles so that they are ordered as:

//  1  2  3  4
//  5  6  7  8
//  9 10 11 12
// 13 14 15  x

// where the only legal operation is to exchange 'x' with one of the tiles with which it shares an edge. As an example, the following sequence of moves solves a slightly scrambled puzzle:

//  1  2  3  4     1  2  3  4     1  2  3  4     1  2  3  4
//  5  6  7  8     5  6  7  8     5  6  7  8     5  6  7  8
//  9  x 10 12     9 10  x 12     9 10 11 12     9 10 11 12
// 13 14 11 15    13 14 11 15    13 14  x 15    13 14 15  x
//             r->            d->            r->

// The letters in the previous row indicate which neighbor of the 'x' tile is swapped with the 'x' tile at each step; legal values are 'r','l','u' and 'd', for right, left, up, and down, respectively.

// Not all puzzles can be solved; in 1870, a man named Sam Loyd was famous for distributing an unsolvable version of the puzzle, and
// frustrating many people. In fact, all you have to do to make a regular puzzle into an unsolvable one is to swap two tiles (not counting the missing 'x' tile, of course).

// In this problem, you will write a program for solving the less well-known 8-puzzle, composed of tiles on a three by three
// arrangement.
// Input
// You will receive, several descriptions of configuration of the 8 puzzle. One description is just a list of the tiles in their initial positions, with the rows listed from top to bottom, and the tiles listed from left to right within a row, where the tiles are represented by numbers 1 to 8, plus 'x'. For example, this puzzle

// 1 2 3
// x 4 6
// 7 5 8

// is described by this list:

// 1 2 3 x 4 6 7 5 8
// Output
// You will print to standard output either the word ``unsolvable'', if the puzzle has no solution, or a string consisting entirely of the letters 'r', 'l', 'u' and 'd' that describes a series of moves that produce a solution. The string should include no spaces and start at the beginning of the line. Do not print a blank line between cases.
// Sample
// Input复制	Output复制
// 2  3  4  1  5  x  7  6  8
// ullddrurdllurdruldr






// 15 拼图已有超过百年的历史；即便您对这个名字不熟悉，也一定见过它。它由 15 个可滑动的方块组成，每个方块上标有数字 1 至 15，全部置于一个 4×4 的方框中，且有一个位置空缺。我们将这个空缺位置称为“x”；拼图的目标是排列方块，使其呈以下顺序：

//  1  2  3  4
//  5  6  7  8
//  9 10 11 12
// 13 14 15  x

// 其中唯一允许的操作是将“x”与其相邻的某个方块（共享一条边）交换位置。例如，以下一系列移动步骤即可解开一个稍微打乱的拼图：

//  1  2  3  4     1  2  3  4     1  2  3  4     1  2  3  4
//  5  6  7  8     5  6  7  8     5  6  7  8     5  6  7  8
//  9  x 10 12     9 10  x 12     9 10 11 12     9 10 11 12
// 13 14 11 15    13 14 11 15    13 14  x 15    13 14 15  x
//             r→            d→            r→

// 上一行中的字母表示每一步与“x”方块交换的相邻方块方向；合法的取值为 'r'、'l'、'u' 和 'd'，分别代表右、左、上、下。

// 并非所有拼图都能解开；1870 年，一位名叫 Sam Loyd 的人因发布了一个无解版本的拼图而闻名，令许多人受挫不已。事实上，要让一个常规拼图变为无解，只需交换两个方块（当然，不包含空缺的“x”方块）。

// 在此问题中，您将编写一个程序来解决较为冷门的 8 拼图，它由置于 3×3 网格中的方块构成。

// **输入**  
// 您将接收若干个 8 拼图的初始布局描述。一个描述就是按其初始位置列出的方块列表，按行从上到下、每行内从左到右的顺序排列，其中方块由数字 1 至 8 以及 'x' 表示。例如，如下拼图  

// 1 2 3  
// x 4 6  
// 7 5 8  

// 将用以下列表描述：  

// 1 2 3 x 4 6 7 5 8  

// **输出**  
// 您应向标准输出打印结果：若拼图无解，则输出单词 ``unsolvable``；否则，输出一个完全由字母 'r'、'l'、'u' 和 'd' 组成的字符串，用以描述产生解法的一系列移动步骤。该字符串不应包含空格，且从行首开始。各测试用例之间请勿打印空行。

// **样例**  
// 输入样例复制	输出样例复制  
// 2  3  4  1  5  x  7  6  8  
// ullddrurdllurdruldr


