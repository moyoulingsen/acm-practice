// This is a very popular game for children. In this game, there's a cube, which consists of 3 * 3 * 3 small cubes. We can unwrap the cube, it will become like this:

//       w w w
//       w w w
//       w w w
// r r r g g g b b b o o o
// r r r g g g b b b o o o
// r r r g g g b b b o o o
//       y y y
//       y y y
//       y y y

// The letters means the color on the small cubes. For example, 'r' means red, 'g' means green, 'y' means yellow....The goal for this game is to rotate the faces of the cube to make each of the faces contains only one color. Note there're exact 6 kind of colors on the cube and there're exact 9 small rectangles totally in any time in the game.

// Do you know how to rotate the faces? I think most of you have known it. But I would like to show it again. When a face is rotated, the configuration of colors in all the adjacent faces changes. For the cube above, after we rotate the green face clock-wise, the last line of 'w' face will become the left column of 'b' face, the left column of 'b' face will become the top line of 'y' face, etc. As you may know, reaching the final position from a scrambled configuration can be quite challenging.

// In this problem, you are given a configuration of the cube, and asked to give a way to reach the final position. To reduce the difficulty, the steps required will never be greater than 5.


// Input

// The input contains an integer in the first line, which indicates the number of the test cases. In each test case, there're exact 10 lines. The first line is an empty line. The next 9 lines contain a configuration. The format can be seen in the sample input. For simplicity, we give an index to each face as follows:

 

//     /---\
//     |   |
//     | 4 |
//     |   |
// /---+---+---+---\
// |   |   |   |   |
// | 0 | 1 | 2 | 3 |
// |   |   |   |   |
// \---+---+---+---/
//     |   |
//     | 5 |
//     |   |
//     \---/

// Note that there's a space between two adjacent letters.


// Output

// For each test case, the first line of the output is the smallest count N of the steps to reach the winning position. If the winning position can't be reached in 5 steps, print -1 in this line. Otherwise print each step in one line in the following N lines. A step contains two integers, the first one means the face index, and the second one means the direction. 1 means clock-wise and -1 means counter clock-wise. If the given position is the winning position, print 0 for such test case simply. If there're multiple solutions, any one is acceptable.


// Sample Input

// 2
//       w w w
//       w w w
//       w w w
// r r r g g g b b b o o o
// r r r g g g b b b o o o
// r r r g g g b b b o o o
//       y y y
//       y y y
//       y y y

//       w w w
//       w w w
//       b b b
// r r w g g g y b b o o o
// r r w g g g y b b o o o
// r r w g g g y b b o o o
//       r r r
//       y y y
//       y y y


// Sample Output

// 0
// 1
// 1 1

// 以下为题目内容的中文翻译（仅翻译，不解答）：

// ---

// 这是一个非常受儿童欢迎的游戏。游戏中有一个立方体，由 3×3×3 的小方块组成。我们可以将立方体展开，展开后的样子如下：

// ```
//       w w w
//       w w w
//       w w w
// r r r g g g b b b o o o
// r r r g g g b b b o o o
// r r r g g g b b b o o o
//       y y y
//       y y y
//       y y y
// ```

// 字母表示小方块上的颜色。例如，`'r'` 表示红色，`'g'` 表示绿色，`'y'` 表示黄色……游戏的目标是旋转立方体的各个面，使得每个面都只包含一种颜色。注意，立方体上恰好有 6 种颜色，且在游戏过程中的任意时刻，每个面恰好有 9 个小方格。

// 你知道如何旋转各个面吗？我想大多数人都已经知道了。但我还是想再展示一次。当一个面被旋转时，所有相邻面上的颜色布局都会发生变化。对于上面展示的立方体，当我们顺时针旋转绿色面后，`'w'` 面的最后一行将变成 `'b'` 面的最左一列，`'b'` 面的最左一列将变成 `'y'` 面的最上一行，依此类推。你可能已经知道，从一个打乱的状态恢复到最终位置是相当具有挑战性的。

// 本题中，你会得到立方体的一个布局，要求你给出一个到达最终位置的方法。为了降低难度，所需步数将不会超过 5。

// **输入**

// 第一行包含一个整数，表示测试用例的数量。每个测试用例恰好包含 10 行。第一行是一个空行。接下来的 9 行描述一个布局。格式可参考样例输入。为简化描述，我们为每个面赋予一个编号，如下所示：

// ```
//     /---\
//     |   |
//     | 4 |
//     |   |
// /---+---+---+---\
// |   |   |   |   |
// | 0 | 1 | 2 | 3 |
// |   |   |   |   |
// \---+---+---+---/
//     |   |
//     | 5 |
//     |   |
//     \---/
// ```

// 注意，两个相邻字母之间有一个空格。

// **输出**

// 对于每个测试用例，输出的第一行是到达获胜位置所需的最小步数 N。如果无法在 5 步内到达获胜位置，则在这一行输出 -1。否则，在接下来的 N 行中每行输出一个步骤。每个步骤包含两个整数：第一个表示面编号，第二个表示旋转方向。1 表示顺时针，-1 表示逆时针。如果给定的位置已经是获胜位置，则对于该测试用例直接输出 0。如果存在多个解，任意一个均可接受。

// **样例输入**

// ```
// 2
//       w w w
//       w w w
//       w w w
// r r r g g g b b b o o o
// r r r g g g b b b o o o
// r r r g g g b b b o o o
//       y y y
//       y y y
//       y y y

//       w w w
//       w w w
//       b b b
// r r w g g g y b b o o o
// r r w g g g y b b o o o
// r r w g g g y b b o o o
//       r r r
//       y y y
//       y y y
// ```

// **样例输出**

// ```
// 0
// 1
// 1 1
// ```