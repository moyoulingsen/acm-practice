#include <bits/stdc++.h>



using namespace std;


bool f(string s){
        for(char v:s){
            if(v == '0'||v == '5')
                return true;
        }
        return false;
        
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;cin.ignore();
    
    
    
    while(n--){
        string s;
        getline(cin,s);

        cout << (f(s)?"YES\n":"NO\n");
    }
    

    return 0;
}