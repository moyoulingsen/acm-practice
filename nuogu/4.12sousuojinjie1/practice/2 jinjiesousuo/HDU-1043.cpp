// HDU-1043
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

// 以下为题目内容的中文翻译（仅翻译，不解答）：

// ---

// **15-puzzle** 已有超过一百年的历史；即便你不清楚这个名字，也一定见过它。它由 15 个可滑动的方块构成，每个方块上标有数字 1 至 15，全部放置在一个 4×4 的方框中，并留有一个空位。我们将这个空位称为 `'x'`；游戏的目标是移动方块，使其排列成以下顺序：

// ```
//  1  2  3  4
//  5  6  7  8
//  9 10 11 12
// 13 14 15  x
// ```

// 唯一合法的操作是将 `'x'` 与和它共享一条边的某个方块交换位置。例如，下面这一系列移动步骤可以解决一个稍微打乱的局面：

// ```
//  1  2  3  4     1  2  3  4     1  2  3  4     1  2  3  4
//  5  6  7  8     5  6  7  8     5  6  7  8     5  6  7  8
//  9  x 10 12     9 10  x 12     9 10 11 12     9 10 11 12
// 13 14 11 15    13 14 11 15    13 14  x 15    13 14 15  x
//             r→            d→            r→
// ```

// 上一行中的字母表示每一步中与 `'x'` 方块交换的相邻方块方向；合法的取值为 `'r'`、`'l'`、`'u'` 和 `'d'`，分别代表右、左、上、下。

// 并非所有局面都能被解开；1870 年，一个名叫 Sam Loyd 的人因推广一个无解版本的谜题而闻名，并让许多人感到沮丧。事实上，将一个常规可解的局面变成无解局面，只需交换任意两个方块（当然不包括空位 `'x'`）即可。

// 本题要求你编写一个程序，用于解决不太为人熟知的 **8-puzzle**，它由放置在 3×3 网格中的方块组成。

// **输入**  
// 你将收到若干组 8-puzzle 局面的描述。每组描述仅为其初始位置的方块列表，行按从上到下的顺序列出，每行内的方块按从左到右的顺序给出，方块由数字 1 至 8 以及 `'x'` 表示。例如，以下局面：

// ```
// 1 2 3
// x 4 6
// 7 5 8
// ```

// 由以下列表描述：

// ```
// 1 2 3 x 4 6 7 5 8
// ```

// **输出**  
// 对于每个局面，如果无解，则向标准输出打印单词 `unsolvable`；如果有解，则输出一个完全由字母 `'r'`、`'l'`、`'u'` 和 `'d'` 组成的字符串，描述一系列产生解法的移动步骤。该字符串不应包含空格，且需从行首开始。两组输出之间不要打印空行。

// **样例**  
// 输入（复制）：

// ```
// 2  3  4  1  5  x  7  6  8
// ```

// 输出（复制）：

// ```
// ullddrurdllurdruldr
// ```


