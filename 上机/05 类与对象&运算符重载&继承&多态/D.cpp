#include <iostream>
using namespace std;

class Base {
public:
    virtual Base& fun() {
        cout << "base fun" << endl;
        return *this;
    }
    virtual Base& foo() {
        cout << "base foo" << endl;
        return *this;
    }
};

class Derived : public Base {
public:
    Base& fun() {
        cout << "derived fun" << endl;
        return *this;
    }
    Base& foo() {
        cout << "derived foo" << endl;
        return *this;
    }
};

Base& foo();
Base& fun();
Base& foo() {
    static Derived d;
    return d.foo();
}
Base& fun() {
    static Base b;
    return b.fun();
}
// 在此处补充你的代码
int main() {
    foo().fun().foo();
    fun().foo().fun();
    system("pause");
    return 0;
}