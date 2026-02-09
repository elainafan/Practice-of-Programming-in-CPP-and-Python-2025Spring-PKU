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
typedef pair<string, int> PAIR;
class MyMap : public map<string, int> {
public:
    map<int, set<pair<int, string>>> ma;
    map<string, int> fma;
    MyMap() {
        ma.clear();
        fma.clear();
    }
    friend istream &operator>>(istream &is, MyMap &other) {
        string tem;
        int temp;
        is >> tem;
        is >> temp;
        if (other.fma.find(tem) == other.fma.end()) {
            other.fma[tem] = 1;
            other.ma[temp].insert(make_pair(tem.size(), tem));
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, MyMap &other) {
        for (auto it = --other.ma.end();; it--) {
            for (auto itt = it->second.begin(); itt != it->second.end(); itt++) {
                cout << (*itt).second << ' ' << it->first << endl;
            }
            if (it == other.ma.begin()) break;
        }
        return os;
    }
    // 在此处补充你的代码
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        MyMap mm;
        for (int i = 0; i < n; ++i) cin >> mm;
        cout << mm;
    }
    system("pause");
    return 0;
}