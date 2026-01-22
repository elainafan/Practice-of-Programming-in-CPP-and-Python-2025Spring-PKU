#include <iostream>
using namespace std;

class Animal {
public:
    Animal() { cout << "Animal constructor...\n"; }
    virtual ~Animal() { cout << "Animal destructor...\n"; }
    Animal(const Animal& rhs) { cout << "Animal Copy Constructor...\n"; }
    virtual void Sound() const { cout << "Animal sound!\n"; }
    virtual Animal* Clone() { return new Animal(*this); }
};

class Cat : public Animal {
public:
    Cat();
    ~Cat();
    virtual void Sound() const;
    Cat(const Cat& other) : Animal(other) { cout << "Cat copy constructor..." << endl; }
    virtual Cat* Clone() { return new Cat(*this); }
};

Cat::Cat() { cout << "Cat constructor...\n"; }
Cat::~Cat() { cout << "Cat destructor...\n"; }
void Cat::Sound() const { cout << "Meow!\n"; }

int main() {
    Animal *a = new Cat, *b = new Animal;
    Animal *a1 = a->Clone(), *b1 = b->Clone();
    a1->Sound();
    b1->Sound();
    delete a;
    delete b;
    delete a1;
    delete b1;
    return 0;
}