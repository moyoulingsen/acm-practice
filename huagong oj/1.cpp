// 设计一个简单的角色战斗系统，实现不同角色的攻击与受伤逻辑。具体要求如下：

// 1.定义抽象基类Character
// （1）包含生命值hp和攻击力atk
// （2）纯虚函数attack(Character &target)
// （3）普通函数isDead()判断是否死亡

// 2.定义派生类战士类Warrior，公有继承Character
// （1）实现attack：对目标造成atk+0.1*hp（向下取整）点伤害
// 3.定义派生类法师类Mage，公有继承Character
// （1）实现attack：对目标造成atk*1.5（向下取整）点伤害

// main函数测试代码如下：

#include <bits/stdc++.h>
using namespace std;

class Character{
    public: int hp,atk;
            // Character(int a,int b):a(hp),b(atk)
            // Character(int a,int b):hp(a),atk(b)
            Character(int a,int b):hp(a),atk(b){}

            // virtual void attack(Character &target);
            virtual void attack(Character &target) = 0;
            // bool isDead(int hp){
            bool isDead(){
                return hp<=0;
            };
            int getHp(){
                return hp;
            }
};

// class Character::class Warrior {
// class Character:class Warrior {
// class Warrior:class Character {
class Warrior : public Character {

    public:
        // Warrior(int a,int b):Character(a,b)
        // Warrior(int a,int b):a(hp),b(atk)
        Warrior(int a,int b):Character(a,b){}
        void attack (Character &target) override{
            int sum = atk + hp*0.1;
            target.hp -= sum;
        }
// };不能忘记
};

class Mage : public Character {
    public:
        Mage(int a,int b):Character(a,b){}
        void attack (Character &target) override{
            int sum = (atk *1.5);
            target.hp -= sum;
        }
};

int main() {
    int wh, wa, mh, ma;
    while (cin >> wh >> wa >> mh >> ma) {
        Warrior w(wh, wa);
        Mage m(mh, ma);
        w.attack(m);
        m.attack(w);
        cout << w.getHp() << " " << m.getHp() << " ";
        bool wd = w.isDead();
        bool md = m.isDead();
        if (wd && md)//都死了
            cout << "Both";
        else if (wd)//战士死了
            cout << "Mage";
        else if (md)//法师死了
            cout << "Warrior";
        else//都活着
            cout << "None";
        cout << endl;
    }
    return 0;
}
