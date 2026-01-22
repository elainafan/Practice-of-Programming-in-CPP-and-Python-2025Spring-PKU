#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
string x;
ll cnt = 0;  // 库存
multimap<int, int> ma;
int n;
int a, b;
ll tot = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x == "BUY") {
            cin >> a;
            ll ans = 0;
            for (auto it = ma.begin(); it != ma.end();) {
                if (a <= 0) break;
                if (it->second <= a) {
                    a -= it->second;
                    ans += it->second * it->first;
                    tot -= it->second * it->first;
                    cnt -= it->second;
                    it = ma.erase(it);
                } else {
                    ans += it->first * a;
                    it->second -= a;
                    tot -= a * it->first;
                    cnt -= a;
                    a = 0;
                }
            }
            if (a > 0) ans += a * 40;
            cout << ans << endl;
        } else if (x == "SELL") {
            cin >> a >> b;
            ma.insert(make_pair(b, a));
            cnt += a;
            tot += a * b;
        }
    }
    system("pause");
    return 0;
}