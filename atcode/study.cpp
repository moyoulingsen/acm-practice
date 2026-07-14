#include <iostream>
using namespace std;

class A {
public:
    int a;
    A(int a) : a(a) {
        cout << "A(" << a << ")\n";
    }
};

class B : virtual public A {
public:
    int b;
    B(int a, int b) : A(a), b(b) {
        cout<<a<<endl;
        cout << "B(" << b << ")\n";
    }
};

class C : virtual public A {
public:
    int c;
    C(int a, int c) : A(a), c(c) {
        cout << "C(" << c << ")\n";
    }
};

class D : public B, public C {
public:
    D(int a, int b, int c) : A(a), B(a, b), C(a, c) {
        cout << "D\n";
    }
};

int main() {
   
    D d(10, 20, 30);
    B b(2,10);
}
