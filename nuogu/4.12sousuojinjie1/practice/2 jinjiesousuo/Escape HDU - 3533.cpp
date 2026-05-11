// The students of the HEU are maneuvering for their military training.
// The red army and the blue army are at war today. The blue army finds that Little A is the spy of the red army, so Little A has to escape from the headquarters of the blue army to that of the red army. The battle field is a rectangle of size m*n, and the headquarters of the blue army and the red army are placed at (0, 0) and (m, n), respectively, which means that Little A will go from (0, 0) to (m, n). The picture below denotes the shape of the battle field and the notation of directions that we will use later.




// The blue army is eager to revenge, so it tries its best to kill Little A during his escape. The blue army places many castles, which will shoot to a fixed direction periodically. It costs Little A one unit of energy per second, whether he moves or not. If he uses up all his energy or gets shot at sometime, then he fails. Little A can move north, south, east or west, one unit per second. Note he may stay at times in order not to be shot.
// To simplify the problem, let’s assume that Little A cannot stop in the middle of a second. He will neither get shot nor block the bullet during his move, which means that a bullet can only kill Little A at positions with integer coordinates. Consider the example below. The bullet moves from (0, 3) to (0, 0) at the speed of 3 units per second, and Little A moves from (0, 0) to (0, 1) at the speed of 1 unit per second. Then Little A is not killed. But if the bullet moves 2 units per second in the above example, Little A will be killed at (0, 1).
// Now, please tell Little A whether he can escape.
// Input
// For every test case, the first line has four integers, m, n, k and d (2<=m, n<=100, 0<=k<=100, m+ n<=d<=1000). m and n are the size of the battle ground, k is the number of castles and d is the units of energy Little A initially has. The next k lines describe the castles each. Each line contains a character c and four integers, t, v, x and y. Here c is ‘N’, ‘S’, ‘E’ or ‘W’ giving the direction to which the castle shoots, t is the period, v is the velocity of the bullets shot (i.e. units passed per second), and (x, y) is the location of the castle. Here we suppose that if a castle is shot by other castles, it will block others’ shots but will NOT be destroyed. And two bullets will pass each other without affecting their directions and velocities.
// All castles begin to shoot when Little A starts to escape.
// Proceed to the end of file.
// Output
// If Little A can escape, print the minimum time required in seconds on a single line. Otherwise print “Bad luck!” without quotes.
// Sample
// Input复制	Output复制
// 4 4 3 10
// N 1 1 1 1
// W 1 1 3 2
// W 2 1 2 4
// 4 4 3 10
// N 1 1 1 1
// W 1 1 3 2
// W 1 1 2 4
// 9
// Bad luck!


// 以下为题目内容的中文翻译（仅翻译，不解答）：

// ---

// 哈尔滨工程大学的学生们正在进行军训演习。  
// 今天红军与蓝军交战。蓝军发现小 A 是红军间谍，因此小 A 必须从蓝军总部逃往红军总部。战场是一个大小为 m×n 的矩形区域，蓝军总部和红军总部分别位于 (0, 0) 和 (m, n)，这意味着小 A 将从 (0, 0) 出发前往 (m, n)。下图展示了战场的形状以及后续将使用的方向标记。





// 蓝军急于复仇，因此竭尽全力在小 A 逃跑途中将其击杀。蓝军布置了许多城堡，每个城堡会周期性地向固定方向射击。小 A 无论移动与否，每秒消耗一单位能量。如果他耗尽所有能量或在某一时刻被击中，则任务失败。小 A 可以每秒向北、南、东、西移动一格。注意，为了躲避子弹，他可以停留在原地。  
// 为简化问题，假设小 A 不能在一秒中间停顿。他在移动过程中既不会被击中，也不会阻挡子弹，这意味着子弹只能在整数坐标位置击杀小 A。考虑以下示例：子弹以每秒 3 格的速度从 (0, 3) 飞向 (0, 0)，小 A 以每秒 1 格的速度从 (0, 0) 移动到 (0, 1)。此时小 A 不会被击中。但若上例中子弹速度为每秒 2 格，则小 A 会在 (0, 1) 处被击中。  
// 现在，请判断小 A 能否成功逃脱。

// **输入**  
// 对于每个测试用例，第一行包含四个整数：m、n、k 和 d（2 ≤ m, n ≤ 100，0 ≤ k ≤ 100，m + n ≤ d ≤ 1000）。m 和 n 为战场尺寸，k 为城堡数量，d 为小 A 初始拥有的能量单位数。接下来 k 行每行描述一座城堡，包含一个字符 c 和四个整数 t、v、x、y。其中 c 为 'N'、'S'、'E' 或 'W'，表示城堡射击的方向；t 为射击周期；v 为射出子弹的速度（即每秒经过的格数）；(x, y) 为城堡位置。此处假设：若城堡被其他城堡射中，它会阻挡射击但不会被摧毁；两发子弹相遇时会相互穿过，不影响各自的方向和速度。  
// 所有城堡在小 A 开始逃跑时同时开始射击。  
// 持续处理输入直至文件结束。

// **输出**  
// 若小 A 能够逃脱，单行输出所需的最短时间（以秒为单位）。否则输出不带引号的 `Bad luck!`。

// **样例**  
// 输入（复制）：

// ```
// 4 4 3 10
// N 1 1 1 1
// W 1 1 3 2
// W 2 1 2 4
// 4 4 3 10
// N 1 1 1 1
// W 1 1 3 2
// W 1 1 2 4
// ```

// 输出（复制）：

// ```
// 9
// Bad luck!
// ```