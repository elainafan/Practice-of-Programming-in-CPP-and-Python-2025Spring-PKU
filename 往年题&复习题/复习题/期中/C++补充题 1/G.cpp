#include <iostream>
#include <set>
#include <string>

using namespace std;

class Counter {
    int cnt;

public:
    Counter() : cnt(0) {}
    virtual void push(void*) = 0;
    virtual string name() = 0;
    void inc() { ++cnt; }
    int number() { return cnt; }
};

template <class T>
class TCounter : public Counter {
private:
    set<T> s;
    string a;

public:
    TCounter(string k) : Counter() { a = k; }
    void push(void* x) {
        T* k = (T*)(x);
        if (s.find(*k) == s.end()) {
            inc();
            s.insert(*k);
        }
        return;
    }
    string name() { return a; }
    // 在此处补充你的代码
};

Counter* build_counter(string name) {
    if (name == "int")
        return new TCounter<int>("int");
    else
        return new TCounter<string>("string");
}

int main() {
    int n, m;
    cin >> n >> m;
    Counter *a = build_counter("int"), *b = build_counter("string");
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a->push(&x);
    }
    for (int i = 0; i < m; ++i) {
        string x;
        cin >> x;
        b->push(&x);
    }
    cout << a->name() << ": " << a->number() << endl;
    cout << b->name() << ": " << b->number();
    system("pause");
    return 0;
}