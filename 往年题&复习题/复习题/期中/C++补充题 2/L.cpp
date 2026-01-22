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
    map<int, vector<string>, greater<int>> ma;
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
            other.ma[temp].push_back(tem);
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, MyMap &other) {
        for (auto it = other.ma.begin(); it != other.ma.end(); it++) {
            sort(it->second.begin(), it->second.end(), [](const string &x, const string &y) {
                if (x.length() == y.length()) return x < y;
                return x.length() < y.length();
            });
            for (int i = 0; i < other.ma[it->first].size(); i++) {
                os << other.ma[it->first][i] << ' ' << it->first << endl;
            }
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