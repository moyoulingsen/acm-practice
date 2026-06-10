#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<Task*> tasks;
        for (int i = 0; i < n; i++) {
            string type;
            string name;
            int p, val;
            cin >> type >> name >> p >> val;
            if (type == "CPU") {
                tasks.push_back(new CPUTask(name, p, val));
            } else if (type == "IO") {
                tasks.push_back(new IOTask(name, p, val));
            }
        }
        // 排序
        sort(tasks.begin(), tasks.end(), cmp);
        // 输出
        for (int i = 0; i < tasks.size(); i++) {
            cout << tasks[i]->name << " "
                 << tasks[i]->getTime() << endl;
        }
        tasks.clear();
    }
    return 0;
}