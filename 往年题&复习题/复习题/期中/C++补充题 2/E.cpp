#include <cstdio>
#include <iostream>
using namespace std;

class f {
private:
    int num;

public:
    f(int x) : num(x) {}
    f operator()(int x) {
        f temp(x + num);
        return temp;
    }
    friend ostream &operator<<(ostream &os, const f &other) {
        os << other.num;
        return os;
    }
    f(int a, int b) : num(a * b) {}
    // 在此处补充你的代码
};

int main() {
    cout << f(4)(5) << endl;
    cout << f(64)(36) << endl;
    cout << f(3)(5)(7) << endl;
    cout << f(3, 8) << endl;
    cout << f(15, 3) << endl;
    cout << f(7, 10) << endl;
    system("pause");
    return 0;
}