#include <bits/stdc++.h>
using namespace std;

class Time{
    public:int h,m,s;
    Time (int h,int m,int s):h(h),m(m),s(s){}
    Time operator+(const Time& other){
        int nh,nm,ns;
        nh = (h+other.h+(m+other.m+(s+other.s)/60)/60)%24;
        nm = (m+other.m+(s+other.s)/60)%60;
        ns = (s+other.s)%60;
        return Time(nh,nm,ns);
    }
    Time& operator++(){
        Time s0(0,0,1);
        *this = *this+s0;
        return *this;
    }
};

ostream& operator<<(ostream &os,const Time &other){
        os << setw(2) << setfill('0') << other.h << ':'
       << setw(2) << setfill('0') << other.m << ':'
       << setw(2) << setfill('0') << other.s;
       return os;
    }

int main() {
    int h1, m1, s1, h2, m2, s2, n;
    while(cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2) {
        Time t1(h1, m1, s1), t2(h2, m2, s2);
        cout << (t1 + t2) << endl;
        cin >> n;
        while(n--) ++t1;
        cout << t1 << endl;
    }
    return 0;
}