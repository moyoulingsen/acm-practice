// Eight-puzzle, which is also called "Nine grids", comes from an old game.

// In this game, you are given a 3 by 3 board and 8 tiles. The tiles are numbered from 1 to 8 and each covers a grid. As you see, there is a blank grid which can be represented as an 'X'. Tiles in grids having a common edge with the blank grid can be moved into that blank grid. This operation leads to an exchange of 'X' with one tile.

// We use the symbol 'r' to represent exchanging 'X' with the tile on its right side, and 'l' for the left side, 'u' for the one above it, 'd' for the one below it.



// A state of the board can be represented by a string S using the rule showed below.



// The problem is to operate an operation list of 'r', 'u', 'l', 'd' to turn the state of the board from state A to state B. You are required to find the result which meets the following constrains:
// 1. It is of minimum length among all possible solutions.
// 2. It is the lexicographically smallest one of all solutions of minimum length.
// Input
// The first line is T (T <= 200), which means the number of test cases of this problem.

// The input of each test case consists of two lines with state A occupying the first line and state B on the second line.
// It is guaranteed that there is an available solution from state A to B.
// Output
// For each test case two lines are expected.

// The first line is in the format of "Case x: d", in which x is the case number counted from one, d is the minimum length of operation list you need to turn A to B.
// S is the operation list meeting the constraints and it should be showed on the second line.
// Sample
// Input复制	Output复制
// 2
// 12X453786
// 12345678X
// 564178X23
// 7568X4123
// Case 1: 2
// dd
// Case 2: 8
// urrulldr

// 以下为题目内容的中文翻译（仅翻译，不解答）：

// ---

// **八数码问题**（又称“九宫格”）源自一个古老的游戏。

// 在该游戏中，你将得到一个 3×3 的棋盘和 8 个方块。方块上标有数字 1 至 8，每个方块占据一个格子。如你所见，存在一个空格子，用 `'X'` 表示。与空格子共享一条边的格子中的方块可以移动到该空格子中。这一操作导致 `'X'` 与某一方块交换位置。

// 我们用符号 `'r'` 表示将 `'X'` 与其右侧的方块交换，`'l'` 表示左侧，`'u'` 表示上方，`'d'` 表示下方。

// 棋盘的一种状态可以由一个字符串 S 按照如下所示的规则来表示。

// 问题要求操作一个由 `'r'`、`'u'`、`'l'`、`'d'` 组成的操作序列，将棋盘从状态 A 转变为状态 B。你需要找到满足以下约束条件的结果：
// 1. 在所有可能的解法中，操作序列长度最短。
// 2. 在所有最短长度的解法中，操作序列的字典序最小。

// **输入**  
// 第一行为 T（T ≤ 200），表示本题的测试用例数量。

// 每个测试用例的输入包含两行，第一行为状态 A，第二行为状态 B。保证从状态 A 到状态 B 存在可行的解法。

// **输出**  
// 对于每个测试用例，应输出两行。

// 第一行的格式为 `"Case x: d"`，其中 x 为从 1 开始计数的用例编号，d 为将 A 转变为 B 所需操作序列的最短长度。  
// 第二行输出满足约束条件的操作序列 S。

// **样例**  
// 输入（复制）：

// ```
// 2
// 12X453786
// 12345678X
// 564178X23
// 7568X4123
// ```

// 输出（复制）：

// ```
// Case 1: 2
// dd
// Case 2: 8
// urrulldr
// ```