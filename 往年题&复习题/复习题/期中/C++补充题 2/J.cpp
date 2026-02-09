#include <string.h>

#include <cstring>
#include <iostream>

using namespace std;
template <class T, class Pred>
T Myaccumulate(T* x, int num, Pred f) {
    T temp = f(*x);
    for (T* it = x + 1; it < x + num; it++) {
        temp += f(*it);
    }
    return temp;
}
template <class T>
class MyAccumulate {
    T temp;

public:
    MyAccumulate() {}
    template <class Pred>
    T operator()(T* x, int num, Pred f) {
        temp = f(*x);
        for (T* it = x + 1; it < x + num; it++) {
            temp += f(*it);
        }
        return temp;
    }
};
int sqr(int n) { return n * n; }
string rev(string s) {
    return string(s.rbegin(), s.rend());
    ;
}
int main() {
    int a[100];
    string b[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    cout << Myaccumulate(a, n, sqr) << endl;
    cout << Myaccumulate(b, n, rev) << endl;
    cout << MyAccumulate<int>()(a, n - 1, sqr) << endl;
    cout << MyAccumulate<string>()(b + 1, n - 1, rev) << endl;
    return 0;
}