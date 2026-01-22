#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define ll long long
#define ull unsigned long long
using namespace std;
int n, x, y, m;
string a, b;
int c;
map<string, int> ma;
map<string, int> fa;
int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        if (ma.find(b) == ma.end())
            ma[b] = c;
        else
            ma[b] += c;
        if (fa.find(b) == fa.end())
            fa[b] = 1;
        else
            fa[b]++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a;
        if (((ma[a] / fa[a] == y && ma[a] % fa[a] != 0) || ma[a] / fa[a] > y) && fa[a] >= x)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}