#include <iostream>
using namespace std;
void print(unsigned int x) {
    for (unsigned int sub = x;; sub = (sub - 1) & x) {
        unsigned int tem = sub ^ x;
        cout << tem << endl;
        if (sub == 0) break;
    }
    return;
    // 在此处补充你的代码
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        unsigned x;
        cin >> x;
        print(x);
    }
    system("pause");
    return 0;
}