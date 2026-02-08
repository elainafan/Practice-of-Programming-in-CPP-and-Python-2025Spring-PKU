#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
template <class T>
struct Equal {
    T operator()(const T& x) { return x; }
};
template <class T, class Pred = Equal<T>>
struct Comparator {
    Pred pd;
    bool operator()(const T& a, const T& b) {
        if (pd(a) == pd(b)) return a < b;
        return pd(a) < pd(b);
    }
};
// 在此处补充你的代码
struct len {
    int operator()(string s) { return s.length(); }
};
int main() {
    int a[8]{4, 2, 1, 3, 5, 6, 8, 7};
    sort(a, a + 8, Comparator<int>());
    for (int x : a) cout << x << " ";
    cout << endl;
    int n;
    vector<string> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), Comparator<string>());
    for (string x : v) cout << x << " ";
    cout << endl;

    sort(v.begin(), v.end(), Comparator<string, len>());
    for (string x : v) cout << x << " ";
    system("pause");
    return 0;
}