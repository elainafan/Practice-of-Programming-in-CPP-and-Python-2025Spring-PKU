#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class MyMap {
private:
    multimap<int, string, greater<int>> ma;
    vector<pair<string, int>> a;

public:
    friend istream &operator>>(istream &is, MyMap &p) {
        string tem;
        int temp;
        is >> tem;
        is >> temp;
        if (std::find(p.a.begin(), p.a.end(), make_pair(tem, temp)) != p.a.end()) return is;
        p.ma.insert(make_pair(temp, tem));
        p.a.push_back(make_pair(tem, temp));
        return is;
    }
    friend ostream &operator<<(ostream &os, const MyMap &p) {
        for (auto it = p.ma.begin(); it != p.ma.end();) {
            os << it->first << ' ';
            vector<string> v;
            int temp = it->first;
            for (;; it++) {
                if (it->first == temp) {
                    v.push_back(it->second);
                } else {
                    break;
                }
            }
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++) {
                os << v[i] << ' ';
            }
            os << endl;
        }
        return os;
    }
};
int main() {
    int n;
    cin >> n;
    MyMap mm;
    for (int i = 0; i < n; ++i) cin >> mm;
    cout << mm;
    return 0;
}