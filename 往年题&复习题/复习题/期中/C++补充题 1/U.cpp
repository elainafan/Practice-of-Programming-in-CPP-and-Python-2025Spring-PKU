#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;
int main() {
    int t;
    int a[100];
    cin >> t;
    while (t--) {
        for (int i = 0; i < 12; ++i) cin >> a[i];
        vector<int> b;
        for (int i = 0; i < 12; i++) {
            b.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        auto las = unique(b.begin(), b.end());
        b.erase(las, b.end());
        ostream_iterator<int> c(cout, " ");
        // 在此处补充你的代码
        std::copy(b.begin(), b.end(), c);
        cout << endl;
    }
    system("pause");
    return 0;
}