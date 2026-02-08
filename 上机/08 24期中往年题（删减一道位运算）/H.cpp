#include <iostream>
using namespace std;
template <class T, class Pred = less<T>>
class MaxFinder {
private:
    T* x;
    T* y;
    Pred pd;

public:
    MaxFinder(T* a, T* b) : x(a), y(b) {}
    T* getMax() {
        T* p = new T();
        p = x;
        for (T* it = x + 1; it != y; it++) {
            if (pd(*p, *it)) p = it;
        }
        return p;
    }
    T* getMax(bool f(T x, T y)) {
        T* p = new T();
        p = x;
        for (T* it = x + 1; it != y; it++) {
            if (f(*p, *it)) p = it;
        }
        return p;
    }
    template <class T1>
    T* getMax(T1 t) {
        T* p = new T();
        p = x;
        for (T* it = x + 1; it != y; it++) {
            if (t(*p, *it)) p = it;
        }
        return p;
    }
};
// 在此处补充你的代码
bool cmp(int a, int b) { return a % 10 < b % 10; }
struct op {
    bool operator()(int a, int b) { return a % 7 < b % 7; }
};
int main() {
    int a[8];
    for (int i = 0; i < 8; ++i) cin >> a[i];
    MaxFinder<int> mf1(a, a + 8);
    int cmd;
    cin >> cmd;
    switch (cmd) {
        case 0:
            cout << *mf1.getMax() << endl;
            break;
        case 10:
            cout << *mf1.getMax(cmp) << endl;
            break;
        case 7:
            cout << *mf1.getMax(op()) << endl;
    }
    MaxFinder<int, op> mf2(a, a + 8);
    cout << *mf2.getMax() << endl;
    system("pause");
    return 0;
}