// 设计一个 Item 类，表示背包中的物品。每个物品有名称、重量和价值。现在输入若干个物品，要求统计总重量、总价值，并找出价值最高的物品。

// 要求：

// 成员变量：物品名称 name、重量 weight、价值 value
// 构造函数用于初始化物品信息
// 提供 getName() 方法返回物品名称
// 重载 + 运算符，实现两个物品重量和价值相加，名称固定为 Total
// 重载 < 运算符，按照物品价值比较
// 重载 << 运算符，输出物品信息
// 请实现相关类，使下面的 main 函数能够正常运行。

#include<bits/stdc++.h>
using namespace std;
#define int long long

class Item{
    public:
    string name;
    double weight;
    int value;
    Item (string n,double w,int v):name(n),weight(w),value(v){}
    // Item ()
    Item ():name(""),weight(0),value(0){}

    // void getName(){
    //     cout<<name<<endl;
    // }
    string getName(){
        return name;
    }

    Item operator+(Item& a){
        Item sum;
        sum.name = "Total";
        sum.weight = a.weight+weight;
        sum.value = a.value + value;
        return sum;
    }
    bool operator<(Item &a){
        
        if(a.value<value)return false;
        else return true;
    }

    friend ostream& operator<<(ostream& os,Item& a){
        os<<a.name<<" "<<a.weight<<" "<<a.value;
        return os;
    }
};


signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Item total("Total", 0, 0);
        Item best;
        for (int i = 0; i < n; i++) {
            string name;
            double weight;
            int value;
            cin >> name >> weight >> value;
            Item item(name, weight, value);
            cout << "Item: " << item << endl;
            total = total + item;
            if (i == 0 || best < item) {
                best = item;
            }
        }
        cout << "Total: " << total << endl;
        cout << "Best: " << best.getName() << endl;
    }
    return 0;
}