#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 高精度加法函数
string add(string num1, string num2) {
    string res = "";
    int i = num1.size() - 1; // 指向 num1 的最低位（个位）//////很精髓的指针迁移
    int j = num2.size() - 1; // 指向 num2 的最低位（个位）
    int carry = 0;           // 进位标志

    // 只要还有数字没处理完，或者还有进位，就继续循环
    while (i >= 0 || j >= 0 || carry != 0) {
        // 如果对应位有数字则取出，否则当 0 处理
        int x = (i >= 0) ? num1[i] - '0' : 0;
        int y = (j >= 0) ? num2[j] - '0' : 0;
        
        // 计算当前位的和
        int sum = x + y + carry;
        
        // 更新进位（满 10 进 1）
        carry = sum / 10;
        
        // 将当前位的结果（sum 的个位数）追加到结果字符串中
        res += to_string(sum % 10);
        
        // 指针前移
        i--;
        j--;
    }

    // 因为我们是从个位开始计算并追加的，所以此时的字符串是反的，需要反转过来
    reverse(res.begin(), res.end());
    
    return res;
}

int main() {
    string a, b;
    // 直接读入两个超大整数（如 500 位）
    cin >> a >> b;
    
    cout << add(a, b) << "\n";
    
    return 0;
}
