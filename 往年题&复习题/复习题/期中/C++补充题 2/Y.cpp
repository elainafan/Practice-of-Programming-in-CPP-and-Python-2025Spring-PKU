#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
string x, y;
int a, n, m, k;
map<string, multimap<string, int>> ma;
map<string, multiset<string>> rem;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> a;
        ma[x].insert({y, a});
        rem[y].insert(x);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string temp[105];
        vector<pair<string, int>> tem;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> temp[j];
        }
        for (auto it = rem.begin(); it != rem.end(); it++) {
            int ans = 0;
            int flag = 1;
            for (int j = 1; j <= k; j++) {
                if (it->second.find(temp[j]) == it->second.end()) {
                    flag = 0;
                    break;
                }
                auto itt = ma[temp[j]].find(it->first);
                ans += itt->second;
            }
            if (flag) {
                tem.push_back(make_pair(it->first, ans));
            }
        }
        sort(tem.begin(), tem.end(), [](const pair<string, int> x, const pair<string, int> y) {
            if (x.second == y.second) return x.first < y.first;
            return x.second > y.second;
        });
        cout << tem[0].first << endl;
    }
    system("pause");
    return 0;
}