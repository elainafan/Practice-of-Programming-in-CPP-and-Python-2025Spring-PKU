#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
template <class T>
class MySet {
private:
    set<T, greater<T>> ma;

public:
    MySet() { ma.clear(); }
    void insert(T x) { ma.insert(x); }
    auto begin() const { return ma.begin(); }
    auto end() const { return ma.end(); };
    auto find(T x) const { return ma.find(x); }
    void erase(auto x) { ma.erase(x); }
    void erase(auto x, auto y) {
        for (auto it = x; it != y; it++) {
            ma.erase(ma.find(*it));
        }
    }
};
// 在此处补充你的代码
struct A {
    int n;
    A(int i) : n(i) {}
    operator int() { return n; }
    bool operator>(const A& a) const { return n > a.n; }
};
template <class IT>
void print(IT s, IT e) {
    for (; s != e; ++s) cout << *s << ",";
    cout << endl;
}
int main() {
    MySet<int> mst;
    for (int i = 0; i < 10; ++i) mst.insert(i);
    print(mst.begin(), mst.end());
    int a[] = {1, 2, 3, 4};
    mst.erase(a, a + 3);
    print(mst.begin(), mst.end());

    A b[] = {{7}, {8}};
    mst.erase(b, b + 2);
    print(mst.begin(), mst.end());
    mst.erase(mst.find(6));
    print(mst.begin(), mst.end());
    for (int i = 0; i < 1000000; ++i) mst.insert(i);
    for (int i = 0; i < 1000000 - 10; ++i) mst.erase(mst.find(i));
    int n;
    cin >> n;
    MySet<A> msta;

    for (int i = 0; i < n; ++i) {
        string cmd;
        int n;
        cin >> cmd >> n;
        if (cmd == "ADD")
            msta.insert(A(n));
        else {
            if (msta.find(A(n)) != msta.end())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}