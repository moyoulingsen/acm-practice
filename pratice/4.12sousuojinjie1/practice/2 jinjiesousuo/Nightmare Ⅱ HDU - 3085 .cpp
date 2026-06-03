// Last night, little erriyue had a horrible nightmare. He dreamed that he and his girl friend were trapped in a big maze separately. More terribly, there are two ghosts in the maze. They will kill the people. Now little erriyue wants to know if he could find his girl friend before the ghosts find them.
// You may suppose that little erriyue and his girl friend can move in 4 directions. In each second, little erriyue can move 3 steps and his girl friend can move 1 step. The ghosts are evil, every second they will divide into several parts to occupy the grids within 2 steps to them until they occupy the whole maze. You can suppose that at every second the ghosts divide firstly then the little erriyue and his girl friend start to move, and if little erriyue or his girl friend arrive at a grid with a ghost, they will die.
// Note: the new ghosts also can devide as the original ghost.
// Input
// The input starts with an integer T, means the number of test cases.
// Each test case starts with a line contains two integers n and m, means the size of the maze. (1<n, m<800)
// The next n lines describe the maze. Each line contains m characters. The characters may be:
// ‘.’ denotes an empty place, all can walk on.
// ‘X’ denotes a wall, only people can’t walk on.
// ‘M’ denotes little erriyue
// ‘G’ denotes the girl friend.
// ‘Z’ denotes the ghosts.
// It is guaranteed that will contain exactly one letter M, one letter G and two letters Z.
// Output
// Output a single integer S in one line, denotes erriyue and his girlfriend will meet in the minimum time S if they can meet successfully, or output -1 denotes they failed to meet.
// Sample
// Input复制	Output复制
// 3
// 5 6
// XXXXXX
// XZ..ZX
// XXXXXX
// M.G...
// ......
// 5 6
// XXXXXX
// XZZ..X
// XXXXXX
// M.....
// ..G...

// 10 10
// ..........
// ..X.......
// ..M.X...X.
// X.........
// .X..X.X.X.
// .........X
// ..XX....X.
// X....G...X
// ...ZX.X...
// ...Z..X..X
// 1
// 1
// -1

// 以下为题目内容的中文翻译（仅翻译，不解答）：

// ---

// 昨晚，小 erriyue 做了一个可怕的噩梦。他梦见自己和女朋友分别被困在一个巨大的迷宫中。更可怕的是，迷宫里有两个鬼魂，它们会杀人。现在小 erriyue 想知道，在鬼魂找到他们之前，他能否先找到自己的女朋友。

// 你可以假设小 erriyue 和他的女朋友可以沿四个方向移动。每秒小 erriyue 可以移动 3 步，而他的女朋友可以移动 1 步。鬼魂十分邪恶，每秒它们都会分裂成若干部分，占据其周围 2 步范围内的格子，直到最终占据整个迷宫。你可以假设每秒鬼魂先进行分裂，然后小 erriyue 和女朋友再开始移动。如果小 erriyue 或女朋友到达一个有鬼魂的格子，他们就会死亡。

// 注意：新分裂出的鬼魂也可以像原始鬼魂一样继续分裂。

// **输入**

// 输入以一个整数 T 开头，表示测试用例的数量。

// 每个测试用例以一行包含两个整数 n 和 m 开始，表示迷宫的大小（1 < n, m < 800）。

// 接下来的 n 行描述迷宫。每行包含 m 个字符，字符的含义如下：

// - `'.'` 表示空地，所有人都可以行走。
// - `'X'` 表示墙，只有人不能通过。
// - `'M'` 表示小 erriyue。
// - `'G'` 表示他的女朋友。
// - `'Z'` 表示鬼魂。

// 保证每个测试用例中恰好包含一个字母 M、一个字母 G 和两个字母 Z。

// **输出**

// 对于每个测试用例，在一行中输出一个整数 S。如果他们能成功相遇，则输出小 erriyue 和女朋友相遇所需的最短时间 S；否则输出 -1 表示他们无法相遇。

// **样例**

// 输入（复制）：

// ```
// 3
// 5 6
// XXXXXX
// XZ..ZX
// XXXXXX
// M.G...
// ......
// 5 6
// XXXXXX
// XZZ..X
// XXXXXX
// M.....
// ..G...

// 10 10
// ..........
// ..X.......
// ..M.X...X.
// X.........
// .X..X.X.X.
// .........X
// ..XX....X.
// X....G...X
// ...ZX.X...
// ...Z..X..X
// ```

// 输出（复制）：

// ```
// 1
// 1
// -1
// ```