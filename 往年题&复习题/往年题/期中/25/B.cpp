#include <iostream>
#include <vector>
using namespace std;
class B {
private:
    static int product;

public:
    B(int x) {
        product *= x;
        cout << product << endl;
    }
    void output() {}
};
int B::product = 1;
int main() {
    int n;
    cin >> n;
    vector<B*> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push_back(new B(x));
    }
    for (int i = 0; i < n; ++i) p[i]->output();
    return 0;
}