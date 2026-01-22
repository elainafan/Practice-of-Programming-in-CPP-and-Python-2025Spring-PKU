#include <iostream>
#include <string>
using namespace std;

template <class T>
void print(T a) {
    cout << a << endl;
}

class MyString {
public:
    string m_data;
    MyString(string a) : m_data(a) {}
    friend ostream &operator<<(ostream &os, const MyString &other) {
        os << other.m_data;
        return os;
    }
    string operator+(const MyString &other) { return m_data + other.m_data; }
};
template <class T>
class MyTemplateClass {
private:
    T x;

public:
    MyTemplateClass(T t) : x(t) {}
    operator T() { return x; }
    friend ostream &operator<<(ostream &os, MyTemplateClass &other) {
        os << other.x + other.x;
        return os;
    }
};
// 在此处补充你的代码
int main() {
    int m;
    int num;
    string str;
    cin >> m;
    for (; m > 0; m--) {
        cin >> num >> str;
        MyTemplateClass<int> obj(num);
        print(int(obj));
        print(obj);
        MyTemplateClass<MyString> obj2(str);
        print(MyString(obj2));
        print(obj2);
    }
    system("pause");
    return 0;
}