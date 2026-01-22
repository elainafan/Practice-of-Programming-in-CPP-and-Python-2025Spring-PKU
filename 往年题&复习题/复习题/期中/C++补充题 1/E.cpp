#include <iostream>
#include <vector>
using namespace std;
class A {
private:
    int x;
    static int presum;

public:
    A(int t) : x(t) {}
    void output() {
        presum += x;
        cout << presum << endl;
    }
    // 在此处补充你的代码
};
int A::presum = 0;
int main() {
    int n;
    cin >> n;
    vector<A*> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push_back(new A(x));
    }
    for (int i = 0; i < n; i++) {
        p[i]->output();
    }
    system("pause");
    return 0;
}