#include <iostream>
using namespace std;
class MyCin {
private:
    bool flag;

public:
    MyCin() : flag(true) {}
    MyCin &operator>>(int &n) {
        if (!flag) return *this;
        cin >> n;
        if (n == -1) flag = false;
        return *this;
    }
    operator bool() { return flag; }
    // 在此处补充你的代码
};
int main() {
    MyCin m;
    int n1, n2;
    while (m >> n1 >> n2) cout << n1 << " " << n2 << endl;
    return 0;
}