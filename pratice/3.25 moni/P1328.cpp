#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int  f(int a,int b){
        if (a == b) return 0;
        if (a == 0){
            if(b == 1||b ==4)return 1;
            else return 2;
        }
        if (a == 1){
            if(b == 2||b ==4)return 1;
            else return 2;
        }         
        if (a == 2){
            if(b == 0||b ==3)return 1;
            else return 2;
        } 
        if (a == 3){
            if(b == 0||b ==1)return 1;
            else return 2;
        } 
        if (a == 4){
            if(b == 2||b ==3)return 1;
            else return 2;
        } 
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c;
    cin>>a>>b>>c;

    

    vector<int> brr(b);
    for(int i=0;i<b;i++){
        cin>>brr[i];
    }
    vector<int> crr(c);
    for(int i=0;i<c;i++){
        cin>>crr[i];
    }
   
    int ansa=0;
    int ansb=0;
    for(int i = 0;i<a;i++){
        int ans = f(brr[i%b],crr[i%c]);
        if(ans == 0) continue;
        if(ans == 1) ansb++;
        if(ans == 2) ansa++;
    }
    cout<< ansa << " " << ansb;

    return 0;
}

/*
有的时候胜负表可以快速，不费脑子的判断加减
*/