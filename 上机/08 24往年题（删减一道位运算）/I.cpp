#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int m, n;
map<string, int> p;
map<string, int> ma;
string s;
int ans, a, b;
string x, y;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s >> a >> b;
        p[s] = a;
        ma[s] = b;
    }
    for (int i = 1; i <= n; i++) {
        cin >> s >> x >> y;
        if (ma[s] > 0) {
            ma[s]--;
            ans += p[s];
        }
        if (ma[x] > 0) {
            ma[x]--;
            ans += p[x];
        }
        if (ma[y] > 0) {
            ma[y]--;
            ans += p[y];
        }
    }
    cout << ans << endl;
    return 0;
}