#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
int n;
int main() {
    cin >> n;
    stack<double> ma;
    multiset<double> res;
    for (int i = 1; i <= n; i++) {
        double x;
        cin >> x;
        res.insert(x);
    }
    string x;
    while (cin >> x) {
        if (x == "=") {
            double s = ma.top();
            printf("%e\n", s);
            ma.pop();
            auto it = res.begin();
            res.erase(it);
            res.insert(s);
        } else if (x == "+" || x == "-" || x == "*" || x == "/" || x == "^") {
            double a, b, c;
            a = ma.top();
            ma.pop();
            b = ma.top();
            ma.pop();
            if (x == "+") {
                c = a + b;
            } else if (x == "-") {
                c = b - a;
            } else if (x == "*") {
                c = a * b;
            } else if (x == "/") {
                c = b / a;
            } else {
                c = pow(b, a);
            }
            ma.push(c);
        } else {
            double num;
            num = atof(x.c_str());
            ma.push(num);
        }
    }
    cout << endl;
    int count = 0;
    for (auto it = res.begin(); it != res.end(); it++) {
        count++;
        if (count % 10 == 0) {
            printf("%e\n", *it);
        } else {
            printf("%e ", *it);
        }
    }
    system("pause");
    return 0;
}