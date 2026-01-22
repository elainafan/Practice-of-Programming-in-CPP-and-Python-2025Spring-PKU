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
    bool zzl;  // 直接连
    bool jzl;  // 间接连
    int tot;
    int &temp;
    Computer(Network &s) : zzl(true), jzl(false), tot(0), temp(s.totalConnections) { s.totalConnections++; }
    Computer(Computer &s) : zzl(s.zzl), jzl(s.jzl), tot(0), temp(s.temp) {
        if (temp == 2) temp = 3;
        s.tot++;
    }
    void disConnect() {
        zzl = false;
        temp -= (tot + 1);
        if (temp == 0) cout << "lostAllConnections" << endl;
    }
    void connect(Network &s) {
        s.totalConnections += tot + 1;
        jzl = true;
    }
    void operator=(Computer &s) {
        zzl = true;
        jzl = false;
        s.tot--;
    }
    ~Computer() {
        temp--;
        if (temp == 0) cout << "lostAllConnections" << endl;
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
    Computer *pc3 = new Computer(c2);
    net.print();
    c1.disConnect();
    net.print();
    delete pc3;
    net.print();
    system("pause");
    return 0;
}
// 难点是一个断了之后，直接链接和间接连接的都断了