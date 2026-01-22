#include <iostream>
#include <map>
using namespace std;
class A {
public:
    static int count;
    A(int x) { count++; }
    A() { count++; }
    virtual ~A() { cout << "A::destructor" << endl; }
};
class B : public A {
public:
    B(int x) {}
    ~B() {
        if (count == 4) count--;
        cout << "B::destructor" << endl;
    }
};
// 在此处补充你的代码
int A::count = 0;
void func(B b) {}
int main() {
    A a1(5), a2;
    cout << A::count << endl;
    B b1(4);
    cout << A::count << endl;
    func(b1);
    cout << A::count << endl;
    A* pa = new B(4);
    cout << A::count << endl;
    delete pa;
    cout << A::count << endl;
    return 0;
}