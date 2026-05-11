// Let's play a card game called Gap.
// You have 28 cards labeled with two-digit numbers. The first digit (from 1 to 4) represents the suit of the card, and the second digit (from 1 to 7) represents the value of the card.

// First, you shu2e the cards and lay them face up on the table in four rows of seven cards, leaving a space of one card at the extreme left of each row. The following shows an example of initial layout.



// Next, you remove all cards of value 1, and put them in the open space at the left end of the rows: "11" to the top row, "21" to the next, and so on.

// Now you have 28 cards and four spaces, called gaps, in four rows and eight columns. You start moving cards from this layout.



// At each move, you choose one of the four gaps and fill it with the successor of the left neighbor of the gap. The successor of a card is the next card in the same suit, when it exists. For instance the successor of "42" is "43", and "27" has no successor.

// In the above layout, you can move "43" to the gap at the right of "42", or "36" to the gap at the right of "35". If you move "43", a new gap is generated to the right of "16". You cannot move any card to the right of a card of value 7, nor to the right of a gap.

// The goal of the game is, by choosing clever moves, to make four ascending sequences of the same suit, as follows.



// Your task is to find the minimum number of moves to reach the goal layout.
// Input
// The input starts with a line containing the number of initial layouts that follow.

// Each layout consists of five lines - a blank line and four lines which represent initial layouts of four rows. Each row has seven two-digit numbers which correspond to the cards.
// Output
// For each initial layout, produce a line with the minimum number of moves to reach the goal layout. Note that this number should not include the initial four moves of the cards of value 1. If there is no move sequence from the initial layout to the goal layout, produce "-1".
// Sample
// Input复制	Output复制
// 4

// 12 13 14 15 16 17 21
// 22 23 24 25 26 27 31
// 32 33 34 35 36 37 41
// 42 43 44 45 46 47 11

// 26 31 13 44 21 24 42
// 17 45 23 25 41 36 11
// 46 34 14 12 37 32 47
// 16 43 27 35 22 33 15

// 17 12 16 13 15 14 11
// 27 22 26 23 25 24 21
// 37 32 36 33 35 34 31
// 47 42 46 43 45 44 41

// 27 14 22 35 32 46 33
// 13 17 36 24 44 21 15
// 43 16 45 47 23 11 26
// 25 37 41 34 42 12 31

// 以下为题目内容的中文翻译（仅翻译，不解答）：

// ---

// 让我们来玩一个名为 **Gap** 的纸牌游戏。  
// 你有 28 张标有两位数字的牌。第一位数字（1 至 4）代表牌的花色，第二位数字（1 至 7）代表牌的点数。

// 首先，你将牌洗匀，牌面朝上摆放在桌上，排成四行，每行七张，并且在每行的最左端留出一个牌的空位。下图展示了一种初始布局的示例。



// 接着，你移除所有点数为 1 的牌，并将它们放置在各行左端的空位中：将 `"11"` 放在第一行，`"21"` 放在下一行，依此类推。

// 现在你有 28 张牌和四个空位（称为 gaps），分布在四行八列的格局中。你开始从这个布局移动牌。



// 每次移动，你选择四个空位中的一个，并用该空位左侧牌的后继牌来填充该空位。一张牌的后继牌是指同花色中的下一张牌（如果存在的话）。例如，`"42"` 的后继牌是 `"43"`，而 `"27"` 没有后继牌。

// 在上述布局中，你可以将 `"43"` 移到 `"42"` 右侧的空位，或将 `"36"` 移到 `"35"` 右侧的空位。如果你移动了 `"43"`，在 `"16"` 的右侧会产生一个新的空位。你不能将任何牌移到点数为 7 的牌右侧，也不能移到空位的右侧。

// 游戏的目标是，通过巧妙的移动，组成四条同花色的递增序列，如下所示。



// 你的任务是求出达到目标布局所需的最少移动步数。

// **输入**  
// 输入以一个整数开头，表示接下来初始布局的数量。

// 每个布局由五行组成——一个空行以及代表四行初始布局的四行数据。每行包含七个两位数字，对应七张牌。

// **输出**  
// 对于每个初始布局，输出一行，包含达到目标布局所需的最少移动步数。注意，该步数不应包括最初移动四张点数为 1 的牌的那几步。如果从初始布局到目标布局不存在任何移动序列，则输出 `-1`。

// **样例**  
// 输入（复制）：

// ```
// 4

// 12 13 14 15 16 17 21
// 22 23 24 25 26 27 31
// 32 33 34 35 36 37 41
// 42 43 44 45 46 47 11

// 26 31 13 44 21 24 42
// 17 45 23 25 41 36 11
// 46 34 14 12 37 32 47
// 16 43 27 35 22 33 15

// 17 12 16 13 15 14 11
// 27 22 26 23 25 24 21
// 37 32 36 33 35 34 31
// 47 42 46 43 45 44 41

// 27 14 22 35 32 46 33
// 13 17 36 24 44 21 15
// 43 16 45 47 23 11 26
// 25 37 41 34 42 12 31
// ```

// 输出（复制）：

// ```
// 0
// -1
// -1
// -1
// ```