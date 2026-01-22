#include <iomanip>
#include <iostream>
using namespace std;

class TNone {};
TNone None;
template <class T>
class Option {
private:
    bool valu;
    T val;

public:
    Option(T x) : val(x), valu(true) {}
    Option() : valu(false) {}
    bool has_value() { return valu; }
    T& operator*() { return val; }
    T operator*() const { return val; }
    T value() { return val; }
    Option(TNone& other) : valu(false) {}
    operator bool() { return valu; }
    operator bool() const { return valu; }
};
// 在此处补充你的代码
int main() {
    cout << boolalpha;

    Option<int> a(0), b, c(1);
    cout << a.has_value() << endl;
    cout << b.has_value() << endl;
    b = a;
    *b += 10;
    cout << a.value() << endl;
    cout << b.value() << endl;
    c = None;
    cout << c.has_value() << endl;

    Option<Option<int> > x = None;
    const Option<Option<int> > y = a;
    Option<Option<int> > z = c;
    if (x) cout << "x has value" << endl;
    if (y) cout << "y has value" << endl;
    if (z) cout << "z has value" << endl;
    x = y;
    x = x;
    *x = b;
    **x = 20;
    cout << x.value().value() + **y << endl;
    system("pause");
    return 0;
}