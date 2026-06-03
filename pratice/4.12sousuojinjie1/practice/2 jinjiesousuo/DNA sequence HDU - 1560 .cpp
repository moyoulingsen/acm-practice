// The twenty-first century is a biology-technology developing century. We know that a gene is made of DNA. The nucleotide bases from which DNA is built are A(adenine), C(cytosine), G(guanine), and T(thymine). Finding the longest common subsequence between DNA/Protein sequences is one of the basic problems in modern computational molecular biology. But this problem is a little different. Given several DNA sequences, you are asked to make a shortest sequence from them so that each of the given sequence is the subsequence of it.

// For example, given "ACGT","ATGC","CGTT" and "CAGT", you can make a sequence in the following way. It is the shortest but may be not the only one.


// Input
// The first line is the test case number t. Then t test cases follow. In each case, the first line is an integer n ( 1<=n<=8 ) represents number of the DNA sequences. The following k lines contain the k sequences, one per line. Assuming that the length of any sequence is between 1 and 5.
// Output
// For each test case, print a line containing the length of the shortest sequence that can be made from these sequences.
// Sample
// Input复制	Output复制
// 1
// 4
// ACGT
// ATGC
// CGTT
// CAGT

// 以下为题目内容的中文翻译（仅翻译，不解答）：

// ---

// 二十一世纪是生物技术发展的世纪。我们知道基因由 DNA 构成。组成 DNA 的核苷酸碱基包括 A（腺嘌呤）、C（胞嘧啶）、G（鸟嘌呤）和 T（胸腺嘧啶）。寻找 DNA/蛋白质序列之间的最长公共子序列是现代计算分子生物学的基本问题之一。但本题稍有不同。给定若干 DNA 序列，要求你构造一个最短序列，使得给定的每个序列都是该序列的子序列。

// 例如，给定 "ACGT"、"ATGC"、"CGTT" 和 "CAGT"，你可以按以下方式构造一个序列。该序列为最短，但可能不是唯一的。


// **输入**  
// 第一行为测试用例数 t。接下来包含 t 个测试用例。每个用例的第一行为一个整数 n（1 ≤ n ≤ 8），表示 DNA 序列的数量。接下来的 n 行包含这 n 个序列，每行一个。假定任一序列的长度介于 1 到 5 之间。

// **输出**  
// 对于每个测试用例，输出一行，包含能够从这些序列构造出的最短序列的长度。

// **样例**  
// 输入（复制）：

// ```
// 1
// 4
// ACGT
// ATGC
// CGTT
// CAGT
// ```

// 输出（复制）：

// ```
// 8
// ```