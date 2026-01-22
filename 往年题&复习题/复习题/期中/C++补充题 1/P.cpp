#include <iostream>
#include <set>
using namespace std;
class Rectangle {
public:
    int l, w;
    int c, s;
    Rectangle(int a, int b) : l(a), w(b) {
        c = 2 * (a + b);
        s = a * b;
    }
    friend ostream &operator<<(ostream &os, const Rectangle &t) {
        os << t.s << ' ' << t.c;
        return os;
    }
    bool operator<(const Rectangle &k) const {
        if (s == k.s) return c > k.c;
        return s > k.s;
    }
};
struct Comp {
    bool operator()(Rectangle a, Rectangle b) const {
        if (a.c == b.c) return a.s < b.s;
        return a.c < b.c;
    }
};
// 在此处补充你的代码
int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
    system("pause");
    return 0;
}