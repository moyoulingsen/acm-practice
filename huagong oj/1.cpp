#include <bits/stdc++.h>
using namespace std;

class Character{
    public: int hp,atk;
            void attack(Character &target);
            bool isDead();
};

class Character::class Warrier {
    public:int wh,wa;
           
}

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
