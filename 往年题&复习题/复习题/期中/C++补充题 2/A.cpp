#include <iostream>
using namespace std;

class A {
public:
    static int a, b;
    A() {
        a += 2;
        b++;
    }
    ~A() {
        a--;
        b--;
    }
    // 在此处补充你的代码
};
int A::a = 0;
int A::b = 0;

int main() {
    A x;
    {
        A y;
        cout << "1: " << A::a << " " << A::b << endl;
    }
    cout << "2: " << A::a << " " << A::b << endl;

    A *p = new A();
    cout << "3: " << A::a << " " << A::b << endl;

    delete p;
    cout << "4: " << A::a << " " << A::b << endl;
    system("pause");
    return 0;
}