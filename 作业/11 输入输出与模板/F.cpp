#include <cstring>
#include <iostream>
#include <string>

using namespace std;
template <class T>
class myclass {
    int size;
    T* p;

public:
    myclass(T* k, int b) : size(b) {
        p = new T[size];
        for (int i = 0; i < size; i++) {
            p[i] = k[i];
        }
    }
    // 在此处补充你的代码
    ~myclass() { delete[] p; }
    void Show() {
        for (int i = 0; i < size; i++) {
            cout << p[i] << ",";
        }
        cout << endl;
    }
};
int a[100];
int main() {
    char line[100];
    while (cin >> line) {
        myclass<char> obj(line, strlen(line));
        ;
        obj.Show();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        myclass<int> obj2(a, n);
        obj2.Show();
    }
    system("pause");
    return 0;
}