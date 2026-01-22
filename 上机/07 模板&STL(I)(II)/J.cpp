#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
template <class T>
class CArray3D {
private:
    int x, y, z;
    T* p;

public:
    CArray3D(int a, int b, int c) : x(a), y(b), z(c) { p = new T[x * y * z]; }
    class CArray2D {
    private:
        int y, z;
        T* dd;

    public:
        CArray2D(T* d, int b, int c) : dd(d), y(b), z(c) {}
        T* operator[](int index) {
            T* t = dd + index * z;
            return t;
        }
    };
    CArray2D operator[](int index) {
        T* dd = p + index * y * z;
        return CArray2D(dd, y, z);
    }
    operator T*() { return p; }
    // 在此处补充你的代码
};

CArray3D<int> a(3, 4, 5);
CArray3D<double> b(3, 2, 2);
void PrintA() {
    for (int i = 0; i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 5; ++k) cout << a[i][j][k] << ",";
            cout << endl;
        }
    }
}
void PrintB() {
    for (int i = 0; i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) cout << b[i][j][k] << ",";
            cout << endl;
        }
    }
}

int main() {
    int No = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 5; ++k) a[i][j][k] = No++;
    PrintA();
    memset(a, -1, 60 * sizeof(int));  // 注意这里
    memset(a[1][1], 0, 5 * sizeof(int));
    PrintA();

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k) b[i][j][k] = 10.0 / (i + j + k + 1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;
    system("pause");
    return 0;
}