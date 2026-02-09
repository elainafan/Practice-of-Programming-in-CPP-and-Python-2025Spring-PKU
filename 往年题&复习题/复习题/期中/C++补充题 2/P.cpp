#include <iostream>
using namespace std;

class A {
public:
    static int total;
    int num;
    A() { total++; }
    A(int x, int y) { total++; }
    A(int x) { total++; }
    A(const A &other) { total++; }
    operator int() { return num; }
    ~A() { total--; }
    // 在此处补充你的代码
};

int A::total = 0;

int main() {
    A array1[4];
    cout << A::total << "\n";
    A array2[4] = {1, A(1, 1)};
    cout << A::total << "\n";
    A a(array1[0]);
    cout << A::total << "\n";
    A *p = new A();
    cout << A::total << "\n";
    delete p;
    cout << A::total << "\n";
    system("pause");
    return 0;
}