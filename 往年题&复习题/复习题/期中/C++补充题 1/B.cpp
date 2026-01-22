#include <cstdio>
#include <iostream>
using namespace std;

class f {
private:
    int x;

public:
    f(int t) : x(t) {}
    f(int a, int b) { x = a * b; }
    int operator()(int k) { return k - x; }
    friend ostream &operator<<(ostream &os, const f &t) {
        os << t.x;
        return os;
    }
    // 在此处补充你的代码
};

int main() {
    cout << f(3)(5) << endl;
    cout << f(4)(10) << endl;
    cout << f(114)(514) << endl;
    cout << f(9, 7) << endl;
    cout << f(2, 3) << endl;
    cout << f(2, 5) << endl;
    system("pause");
    return 0;
}