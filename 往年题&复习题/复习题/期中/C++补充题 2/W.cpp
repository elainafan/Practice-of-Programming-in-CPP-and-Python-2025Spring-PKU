#include <algorithm>
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
int main() {
    int x, p;
    cin >> x >> p;  // 保证 x 有逆元
    int a[10] = {0, 1, 2, 3, 4, 9, 8, 7, 6, 5};
    sort(a, a + 10, [&](int c, int d) -> bool { return c * x % p < d * x % p || ((c * x % p == d * x % p) && c < d); }
         // 在此处补充你的代码
    );

    for (int i = 0; i < 10; i++) cout << a[i] << endl;
    system("pause");
    return 0;
}