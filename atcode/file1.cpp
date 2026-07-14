#include<iostream>
#include<fstream>

using namespace std;
int main(){
    ofstream op;
    op.open("a.txt");

    op<<"hello";
    op<<" world.\n";
    op<<"12345678"<<endl;
    op<<"  llalala";

    op.close();

    ofstream other(R"(C:\Users\ASUS\Desktop\acm-pracice\atcode\a.txt)",ios::app);
    other<<"\nzailaiyihang";
    
}