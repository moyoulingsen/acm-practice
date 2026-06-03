#include <bits/stdc++.h>
using namespace std;

class StringCounter{
    public:string s;
    StringCounter(string s):s(s){}
    void compress(){
        string ans="";
        int num = 1;
        for(int i = 1;i<s.size();i++){
            if(s[i]==s[i-1]){
                num++;
            }
            else{   ans+=s[i-1];
                    ans+=to_string(num);
                    num = 1;
            }
        }
        ans+=s[s.size()-1];
        ans+=to_string(num);
        
        s = ans;
    }
    void print(){
        cout<<s<<endl;
    }
};



int main(){
    string s;
    while(cin >> s){
        StringCounter sc(s);
        sc.compress();
        sc.print();
    }
    return 0;
}