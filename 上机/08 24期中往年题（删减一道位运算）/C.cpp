#include <iostream>
using namespace std;
class A {
protected:
    int x;

public:
    A(int a = 1) {
        cout << "construct A" << endl;
        x = a;
    }
    virtual void show() { cout << "A:" << x << endl; }
};
class B : public A {
public:
    B() : A(2) { x = 2; }
    virtual void show() {
        cout << "B:" << x << endl;
        cout << "A:" << x << endl;
    }
};
class C : public A {
public:
    C() : A(3) { x = 3; }
    virtual void show() {
        cout << "C:" << x << endl;
        cout << "A:" << x << endl;
    }
};
int main() {
    A a, *pa;
    B b;
    C c;
    pa = &a;
    pa->show();
    pa = &b;
    pa->show();
    pa = &c;
    pa->show();
}