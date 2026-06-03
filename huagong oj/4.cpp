#include<bits/stdc++.h>
using namespace std;
#define int long long

class Fraction {
    public:
    int a,b;
    
    Fraction (int a,int b):a(a),b(b){}

    static Fraction fromStr(string s){
        int pos =s.find('/');
        string s1="";
        string s2="";
        int a,b;
        for(int i=0;i<pos;i++){
            s1+=s[i];  
        }
        a = stoll(s1);
        for(int i=pos+1;i<s.size();i++){
            s2+=s[i];  
        }
        b = stoll(s2);
        return Fraction(a,b);
    }

    void valid(){
        int mmax = gcd(a,b);
        if(mmax!=0){
            a = a/mmax;
            b = b/mmax;
        }
        if(b < 0){
        a = -a;
        b = -b;
    }     ///不读提
    }
    
};

Fraction operator+(const Fraction&n,const Fraction&m){
    
    int a = n.a*m.b+n.b*m.a;
    int b = n.b*m.b;
    Fraction res(a,b);
    res.valid();
    return res;
}
Fraction operator-(const Fraction&n,const Fraction&m){
    
    int a = n.a*m.b-n.b*m.a;
    int b = n.b*m.b;
     Fraction res(a,b);
    res.valid();
    return res;
}
Fraction operator*(const Fraction&n,const Fraction&m){
    
    int a = n.a*m.a;
    int b = n.b*m.b;
    Fraction res(a,b);
    res.valid();
    return res;
}
ostream& operator<<(ostream &os,Fraction cur){
    cur.valid();
    if(cur.a==0){
        os<<0;
    }
    else if(cur.b ==1){
        os<<cur.a;
    }
    else {
        os<<cur.a<<'/'<<cur.b;
    }
    return os;
}

signed main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        Fraction f1 = Fraction::fromStr(s1), f2 = Fraction::fromStr(s2);
        cout << f1+f2 << " "<< f1-f2 << " " << f1*f2 << endl;
    }
    return 0;
}






