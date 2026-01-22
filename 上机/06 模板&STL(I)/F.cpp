#include <iostream>
#include <string>
using namespace std;
template <class T>
class container {
private:
    T k;

public:
    container(T x) : k(x) {}
    T operator+(const container &other) {
        T temp;
        temp = k + other.k + other.k;
        return temp;
    }
    T operator+(T x) {
        T temp;
        temp = k + x;
        return temp;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    container<int> a = n;
    container<int> b = m;
    cout << a + b << endl;
    cout << a + m << endl;
    container<string> sa = string(s1);
    container<string> sb = string(s2);
    cout << sa + sb << endl;
    cout << sa + s2 << endl;
}