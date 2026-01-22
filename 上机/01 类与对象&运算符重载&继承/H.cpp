#include <iostream>
using namespace std;
int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
class Fraction {
    int num, den;

public:
    Fraction(int x, int y) {
        int k = gcd(x, y);
        num = x / k;
        den = y / k;
    }
    Fraction(int x) {
        num = x;
        den = 1;
    }
    Fraction operator*=(const Fraction &s) {
        num *= s.num;
        den *= s.den;
        return *this;
    }
    Fraction operator/=(const Fraction &s) {
        num /= s.num;
        den /= s.den;
        return *this;
    }
    Fraction operator*(const Fraction &s) {
        Fraction temp(num * s.num, den * s.den);
        return temp;
    }
    Fraction operator/(const Fraction &s) {
        Fraction temp(num, den / s.den * s.num);
        return temp;
    }
    operator float() {
        float x = (float)num;
        float y = (float)den;
        return (float)(x / y);
    }
    friend ostream &operator<<(ostream &o, const Fraction &b) {
        o << b.num << '/' << b.den;
        return o;
    }
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    Fraction f(a, b), g(c);
    f *= g;
    cout << f << endl;
    f /= g;
    cout << f << endl;
    f = f * f;
    cout << f << endl;
    f = f / g;
    cout << f << endl;
    cout << (float)f << endl;
    return 0;
}