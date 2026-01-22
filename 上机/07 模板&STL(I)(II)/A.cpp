#include <iostream>
#include <list>
#include <string>

using namespace std;

class A {
private:
    string name;

public:
    A(string n) : name(n) {}
    friend bool operator<(const class A& a1, const class A& a2);
    friend bool operator==(const class A& a1, const class A& a2) {
        if (a1.name.size() == a2.name.size())
            return true;
        else
            return false;
    }
    friend ostream& operator<<(ostream& o, const A& a) {
        o << a.name;
        return o;
    }
    string get_name() const { return name; }
    int get_size() const { return name.size(); }
};
bool operator<(const class A& a1, const class A& a2) { return a1.get_size() < a2.get_size(); }
template <class T>
struct MyLarge {
    bool operator()(const T& a1, const T& a2) { return a1.get_name() < a2.get_name(); }
};
template <class T1, class T2>
void Show(T1 x, T1 y, T2 f) {
    for (auto it = x; it != y; it++) {
        f(*it);
    }
}
struct Print {
    void operator()(const A& a) const { cout << a.get_name() << ' '; }
};
// 在此处补充你的代码
int main(int argc, char* argv[]) {
    list<A> lst;
    int ncase, n, i = 1;
    string s;
    cin >> ncase;
    while (ncase--) {
        cout << "Case: " << i++ << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            lst.push_back(A(s));
        }
        lst.sort();
        Show(lst.begin(), lst.end(), Print());

        cout << endl;
        lst.sort(MyLarge<A>());
        Show(lst.begin(), lst.end(), Print());
        cout << endl;
        lst.clear();
    }
    system("pause");
    return 0;
}