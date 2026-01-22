#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
template <class T>
class CMyClass {
private:
    int siz;
    T* p;

public:
    CMyClass(T* b, int s) : siz(s) {
        p = new T[siz];
        for (int i = 0; i < siz; i++) {
            p[i] = b[i];
        }
    }
    T operator[](int x) { return p[x]; }
};
int a[40];
int main(int argc, char** argv) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) scanf("%d", a + i);
        char s[100];
        scanf("%s", s);
        CMyClass<int> b(a, m);
        CMyClass<char> c(s, strlen(s));
        printf("%d %c\n", b[5], c[7]);
    }
    return 0;
}