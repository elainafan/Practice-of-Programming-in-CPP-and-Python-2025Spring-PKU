#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
class A {
public:
    A() { cout << "New A" << endl; }
    virtual ~A() { cout << "Delete A" << endl; }
};
class B : public A {
public:
    B() { cout << "New B" << endl; }
    ~B() { cout << "Delete B" << endl; }
};
// 在此处补充你的代码
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            A *a = new A();
            delete a;
        } else {
            A *a = new B();
            delete a;
        }
    }
    system("pause");
    return 0;
}