#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
template <class T, int siz>
class A {
private:
    T* p;

public:
    A(T* b) {
        p = new T[siz];
        for (int i = 0; i < siz; i++) {
            p[i] = b[i];
        }
    }
    template <class T1, class T2>
    T1 sum(int x, int y, T1 f(T2 k)) {
        T1 temp = f(p[x]);
        for (int i = x + 1; i <= y; i++) {
            temp += f(p[i]);
        }
        return temp;
    }
};
string int2string(int x) { return to_string(x); }
int int2squareint(int x) { return x * x; }

int string2int(string str) {
    int res = 0;
    for (string::iterator iter = str.begin(); iter != str.end(); ++iter) res += *iter;
    return res;
}
string string2longerstring(string str) { return str + str; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int b1[10];
        for (int i = 0; i < 10; ++i) cin >> b1[i];
        A<int, 10> a1 = b1;
        cout << a1.sum(2, 6, int2squareint) << endl;
        cout << a1.sum(2, 6, int2string) << endl;

        string b2[4];
        for (int i = 0; i < 4; ++i) cin >> b2[i];

        A<string, 4> a2 = b2;
        cout << a2.sum(0, 3, string2int) << endl;
        cout << a2.sum(0, 3, string2longerstring) << endl;
    }
    return 0;
}