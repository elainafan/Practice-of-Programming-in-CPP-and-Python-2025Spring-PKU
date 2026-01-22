#include <iostream>
using namespace std;

class Fighter {
public:
    virtual void attack() { cout << "Fighter::attack()" << endl; }
    virtual void defense() { cout << "Fighter::defense()" << endl; }
};

class Warrior : public Fighter {
public:
    void attack() { cout << "Warrior::attack()" << endl; }
    void defense() { cout << "Warrior::defense()" << endl; }
};

class Mage : public Fighter {
public:
    void attack() { cout << "Mage::attack()" << endl; }
    void defense() { cout << "Mage::defense()" << endl; }
    void castSpell() { cout << "Mage::castSpell()" << endl; }
};

int main() {
    Warrior grom;
    Mage jaina;
    Fighter *p = &grom;
    p->defense();
    p->attack();
    p = &jaina;
    p->attack();
    p->defense();
    jaina.attack();
    jaina.castSpell();
    return 0;
}