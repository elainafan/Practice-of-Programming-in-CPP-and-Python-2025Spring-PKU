#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n;
multiset<int> ma;
set<int> k;
string s;
int x;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> s >> x;
        if (s[1] == 'd') {
            ma.insert(x);
            k.insert(x);
            cout << ma.count(x) << endl;
        } else if (s[1] == 'e') {
            cout << ma.count(x) << endl;
            auto it = ma.find(x);
            while (it != ma.end()) {
                ma.erase(it);
                it = ma.find(x);
            }
        } else {
            if (k.find(x) != k.end())
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
            cout << ma.count(x) << endl;
        }
    }
    system("pause");
    return 0;
}