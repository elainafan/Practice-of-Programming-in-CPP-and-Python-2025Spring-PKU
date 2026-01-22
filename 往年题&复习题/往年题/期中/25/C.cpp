#include <iostream>
using namespace std;

template <class T>
class Multiply {
private:
    T x;

public:
    Multiply(T a) : x(a) {}
    int operator()(T a, T b) { return (int)(a * b + x); }
};
int main() {
    double f;
    int n;
    cin >> f >> n;
    Multiply<double> m1(f);
    Multiply<int> m2(n);
    double x, y;
    int p, q;
    cin >> x >> y >> p >> q;
    cout << m1(x, y) << endl;
    cout << m2(p, q) << endl;
    return 0;
}