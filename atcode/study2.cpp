#include <iostream>
using namespace std;

class A {
public:
    A(int x) { cout << "A " << x << endl; }
};

class B : virtual public A {
public:
    B() : A(1) {cout<<"B"<<endl;}
};

class C : virtual public A {
public:
    C() : A(2) {cout<<"C"<<endl;}
};

class D : public B, public C {
public:
    D() : A(3) {cout<<"D"<<endl;}
};

int main() {
    D d;
}
