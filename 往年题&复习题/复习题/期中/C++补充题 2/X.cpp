#include <iostream>
using namespace std;
struct Network {
    int totalConnections;
    void lostAllConnections() { cout << "lostAllConnections" << endl; }
    Network() : totalConnections(0) {}
    void print() { cout << totalConnections << endl; }
};
class Computer {
public:
    bool con;
    Network* si;
    Computer(Network& s) : con(true), si(&s) { s.totalConnections++; }
    Computer(Computer& d) : con(d.con), si(d.si) {
        if (d.si) d.si->totalConnections++;
    }
    void connect(Network& s) {
        con = true;
        si = &s;
        s.totalConnections++;
    }
    void disConnect() {
        con = false;
        si->totalConnections--;
        if (si->totalConnections == 0) si->lostAllConnections();
        si = nullptr;
    }
    void operator=(const Computer& d) {
        con = d.con;
        si = d.si;
        if (con) si->totalConnections++;
    }
    ~Computer() {
        if (con && si) {
            si->totalConnections--;
            if (si && si->totalConnections == 0) si->lostAllConnections();
        }
    }
    // 在此处补充你的代码
};
int main() {
    Network net;
    Computer c1(net);
    net.print();
    c1.disConnect();
    Computer c2(c1);
    net.print();
    c1.connect(net);
    c2 = c1;
    net.print();
    Computer* pc3 = new Computer(c2);
    net.print();
    c1.disConnect();
    net.print();
    delete pc3;
    net.print();
    system("pause");
    return 0;
}