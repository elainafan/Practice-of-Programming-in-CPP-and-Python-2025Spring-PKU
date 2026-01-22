#include <iostream>
using namespace std;
int gcd(int a, int b) {  // 计算两个数的最大公约数
    return (!b) ? a : gcd(b, a % b);
}
class Fraction {
    int p, q;

public:
    Fraction(int x) {
        p = x;
        q = 1;
    }
    Fraction() {}
    friend istream &operator>>(istream &is, Fraction &x) {
        is >> x.p >> x.q;
        int d = gcd(x.p, x.q);
        x.p /= d;
        x.q /= d;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Fraction &f) {
        if (f.q == 1)
            os << f.p;
        else
            os << f.p << '/' << f.q;
        return os;
    }
    Fraction operator*(const Fraction &b) {
        Fraction temp;
        temp.p = p * b.p;
        temp.q = q * b.q;
        int d = gcd(temp.p, temp.q);
        temp.p /= d;
        temp.q /= d;
        return temp;
    }
    Fraction operator*(int x) {
        Fraction temp;
        temp.p = x * p;
        temp.q = q;
        int d = gcd(temp.p, temp.q);
        temp.p /= d;
        temp.q /= d;
        return temp;
    }
};

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        Fraction a, b, two(2);
        cin >> a >> b;
        cout << a << " * " << b << " = " << a * b << endl;
        cout << "2 * " << a << " = " << two * a << endl;
        cout << b << " * 3 = " << b * 3 << endl;
    }
    return 0;
}