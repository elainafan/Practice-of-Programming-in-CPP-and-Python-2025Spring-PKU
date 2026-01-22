#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>


using namespace std;
class MyFunc {
    int p;

public:
    MyFunc(int x) : p(x) {}
    int operator()(int x) { return pow(x, p); }
    // 在此处补充你的代码
};
int main() {
    int n;
    cin >> n;
    while (n--) {
        vector<MyFunc> v;
        for (int i = 0; i < 5; ++i) v.push_back(MyFunc(i + 1));
        int ans = 1;
        for (int i = 0; i < 5; ++i) {
            int m;
            cin >> m;
            ans += v[i](m);
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}