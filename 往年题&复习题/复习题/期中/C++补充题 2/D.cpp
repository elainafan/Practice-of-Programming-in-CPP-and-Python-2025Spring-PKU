#include <iostream>
#include <string>
using namespace std;

class Slime {
private:
public:
    Slime() { cout << "A slime appears..." << endl; }
    virtual ~Slime() { cout << "A slime disappears..." << endl; }
    virtual string name() { return ""; }
    void attack(Slime* other) {
        cout << name() << ' ';
        cout << "attacked ";
        cout << other->name();
        cout << endl;
    }
    // 在此处补充你的代码
};

class HydroSlime : public Slime {
public:
    string name() { return "Hydro Slime"; }
    HydroSlime() { cout << "A hydro slime appears...\n"; }
    ~HydroSlime() { cout << "A hydro slime disappears...\n"; }
};

class PyroSlime : public Slime {
public:
    string name() { return "Pyro Slime"; }
    PyroSlime() { cout << "A pyro slime appears...\n"; }
    ~PyroSlime() { cout << "A pyro slime disappears...\n"; }
};

int main() {
    Slime *a = new HydroSlime, *b = new PyroSlime;
    a->attack(b);
    b->attack(a);
    delete a;
    delete b;
    system("pause");
    return 0;
}