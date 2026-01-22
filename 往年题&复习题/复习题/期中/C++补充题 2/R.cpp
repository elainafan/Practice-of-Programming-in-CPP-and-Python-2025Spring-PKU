#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class MyMap : public map<string, int> {
public:
    map<int, vector<string>, greater<int>> ma;
    MyMap() { ma.clear(); }
    friend istream &operator>>(istream &is, MyMap &m) {
        string tem;
        int temp;
        is >> tem;
        is >> temp;
        if (std::find(m.ma[temp].begin(), m.ma[temp].end(), tem) == m.ma[temp].end()) m.ma[temp].push_back(tem);
        return is;
    }
    friend ostream &operator<<(ostream &os, MyMap &m) {
        for (auto it = m.ma.begin(); it != m.ma.end(); it++) {
            cout << it->first << ' ';
            sort(it->second.begin(), it->second.end());
            for (int j = 0; j < m.ma[it->first].size(); j++) {
                cout << m.ma[it->first][j] << ' ';
            }
            cout << endl;
        }
        return os;
    }
    // 在此处补充你的代码
};
int main() {
    int n;
    cin >> n;
    MyMap mm;
    for (int i = 0; i < n; ++i) cin >> mm;
    cout << mm;
    system("pause");
    return 0;
}