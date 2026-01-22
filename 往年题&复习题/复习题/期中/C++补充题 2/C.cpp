#include <iostream>
using namespace std;
int count(unsigned int x) {
    // 在此处补充你的代码
    int ans = 0;
    while (x > 0) {
        if (x % 2) ans++;
        x >>= 1;
    }
    return ans;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        unsigned x;
        cin >> x;
        cout << count(x) << endl;
    }
    system("pause");
    return 0;
}