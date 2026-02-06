#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n;
map<int, int> ma;
map<int, int> ma2;
string s;
int x;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s >> x;
        if (s[1] == 'd') {
            ma[x]++;
            ma2[x]++;
            cout << ma[x] << endl;
        } else if (s[1] == 'e') {
            if (ma.count(x)) {
                cout << ma[x] << endl;
                ma.erase(ma.find(x));
            } else
                cout << 0 << endl;
        } else {
            if (ma2.count(x)) {
                cout << 1 << ' ';
                if (ma.count(x))
                    cout << ma[x] << endl;
                else
                    cout << 0 << endl;
            } else
                cout << 0 << endl;
        }
    }
    system("pause");
    return 0;
}