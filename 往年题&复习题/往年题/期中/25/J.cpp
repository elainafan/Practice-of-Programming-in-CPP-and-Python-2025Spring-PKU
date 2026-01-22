#include <iostream>
using namespace std;

template <class T>
class Accumulator {
public:
    T sum;
    Accumulator() { sum = T(); }
    auto getAccumulator() {
        return [=](T x) -> T & {
            sum += x;
            return sum;
        };
    }
    void printval() { cout << sum << endl; }
};

int main() {
    Accumulator<int> A;
    int n;
    cin >> n;
    auto funcA = A.getAccumulator();
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        funcA(v);
    }
    A.printval();

    Accumulator<string> B;
    cin >> n;
    auto funcB = B.getAccumulator();
    for (int i = 0; i < n; i++) {
        string v;
        cin >> v;
        funcB(v);
    }
    B.printval();
    return 0;
}