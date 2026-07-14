


#include <bits/stdc++.h>
using namespace std;

class Task{
    private:
    int priority;

    public:
    string name;
    Task(string n,int p):name(n),priority(p){}
    virtual int getTime() = 0;
    // virtual ~Task(){}
        virtual ~Task() = default;
        int getname(){
            return priority;
        }

    
};

    bool cmp(Task* t1,Task* t2){
        // int p1 = t1.getname();
        // int p2 = t2.getname();
        int p1 = t1->getname();
        int p2 = t2->getname();
        if(p1!=p2){
            return p1>p2;//听不懂什么叫降序是吗？？？
        }
        else return t1->getTime()<t2->getTime();
    }

class CPUTask:public Task{
    private:int cycles;
    
    public:
    // CPUTask(int s,int t,int c):Task(s,t),cycles(c){}
    CPUTask(string s,int t,int c):Task(s,t),cycles(c){}
    int getTime() override{
        return cycles/10;
    }
};
class IOTask:public Task{
    private: int size;
    public:
    IOTask(string s,int t,int c):Task(s,t),size(c){}
    // IOTask(int s,int t,int c):Task(s,t),size(c){}
    int getTime ()override{
        return size/5;
}
};


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