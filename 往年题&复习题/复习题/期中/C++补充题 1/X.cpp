#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int t, n;
string x;
struct node {
    int id, se;
    bool operator<(node x) const {
        if (x.se == se)
            return id > x.id;
        else
            return se < x.se;
    }
};
int num;
int a, b;
priority_queue<node> q[4];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 3; i++) {
            while (!q[i].empty()) {
                q[i].pop();
            }
            num = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x == "IN") {
                cin >> a >> b;
                num++;
                q[a].push(node{num, b});
            } else {
                cin >> a;
                if (q[a].empty()) {
                    cout << "EMPTY" << endl;
                    continue;
                } else {
                    node k = q[a].top();
                    q[a].pop();
                    cout << k.id << endl;
                    continue;
                }
            }
        }
    }
    system("pause");
    return 0;
}