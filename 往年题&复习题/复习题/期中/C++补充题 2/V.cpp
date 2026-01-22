#include <iostream>
using namespace std;

int bitManipulation4(int n) {
    return ((n + 1) & (-(n + 1))) - 1;
    // 在此处补充你的代码
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << bitManipulation4(n) << endl;
    }
    system("pause");
    return 0;
}