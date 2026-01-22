#include <iostream>
using namespace std;

class Counter {
private:
    static int nGlobalNumber;
    int nLocalNumber;

public:
    Counter() {
        nGlobalNumber++;
        if (nGlobalNumber == 2)
            nLocalNumber = 1;
        else
            nLocalNumber = nGlobalNumber;
    }
    Counter(int x) {
        nLocalNumber = x;
        nGlobalNumber++;
    }
    Counter(const Counter& x) {
        nGlobalNumber++;
        nLocalNumber = x.nLocalNumber;
    }
    ~Counter() { nGlobalNumber--; }
    void add(int n) { nLocalNumber += n; }

    void PrintLocalNumber() { cout << nLocalNumber << endl; }
    static void PrintGlobalNumber() { cout << nGlobalNumber << endl; }
};
int Counter::nGlobalNumber = 0;

int main() {
    Counter::PrintGlobalNumber();
    Counter b1, b2;
    Counter::PrintGlobalNumber();
    b1.PrintLocalNumber();
    b2.add(10);
    b2.PrintLocalNumber();
    Counter* b3 = new Counter(7);
    b3->PrintLocalNumber();
    Counter b4 = b2;
    b4.PrintLocalNumber();
    Counter::PrintGlobalNumber();
    if (b3 != NULL) {
        delete b3;
        b3 = NULL;
    }
    Counter::PrintGlobalNumber();

    return 0;
}