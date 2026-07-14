// 设计一个 Car 类，用于计算汽车行驶费用，并比较两辆汽车的费用。

// 要求：

// 成员变量包括汽车名称 name、每公里费用 costPerKm、基础费用 baseCost。
// 构造函数初始化汽车信息。
// 成员函数 getCost(double distance) 返回汽车行驶费用。
// 成员函数 getName() 返回汽车名称。
// 成员函数 isCheaperThan(Car other, double distance) 判断当前汽车费用是否小于等于另一辆汽车。
// 费用计算公式：

// 费用 = 距离 * 每公里费用 + 基础费用

// 请实现相关类 使得下列main得以运行
#include<bits/stdc++.h>
using namespace std;
#define int long long

class Car{
    public:
    string name;
    double costPerKm,baseCost;

    Car(string s,double c,double b):name(s),costPerKm(c),baseCost(b){}
    Car():name(""),costPerKm(0),baseCost(0){}

    double getCost(double distance){
        return distance*costPerKm+ baseCost;
    }
    string getName(){
        return name;
    }
    bool isCheaperThan(Car other, double distance){
        if(getCost(distance)<=other.getCost(distance))return true;
        else return false;
    }
};

signed main() {
    string name1, name2;
    double cost1, cost2;
    double base1, base2;
    double distance;
    while (cin >> name1 >> cost1 >> base1) {
        cin >> name2 >> cost2 >> base2;
        cin >> distance;
        Car car1(name1, cost1, base1);
        Car car2(name2, cost2, base2);
        cout << car1.getName() << ": " << car1.getCost(distance) << endl;
        cout << car2.getName() << ": " << car2.getCost(distance) << endl;
        if (car1.isCheaperThan(car2, distance)) {
            cout << "Cheaper: " << car1.getName() << endl;
        } else {
            cout << "Cheaper: " << car2.getName() << endl;
        }
    }
    return 0;
}