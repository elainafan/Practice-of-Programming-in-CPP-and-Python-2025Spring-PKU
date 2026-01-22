#include <cstring>
#include <iostream>

using namespace std;
template <int bitNum>
struct MyBitset {
    char a[bitNum / 8 + 1];
    MyBitset() { memset(a, 0, sizeof(a)); };
    void Set(int i, int v) {
        char &c = a[i / 8];
        int bp = i % 8;
        if (v)
            c |= (1 << bp);
        else
            c &= ~(1 << bp);
    }
    int myb[20];
    bool flag = false;
    void transform() {
        memset(myb, 0, sizeof(myb));
        for (int i = 0; i <= bitNum / 8 + 1; i++) {
            int temp = i * 8;
            int num = (unsigned char)(a[i]);
            while (num > 0) {
                if (num % 2) myb[temp]++;
                temp++;
                num /= 2;
            }
        }
        flag = true;
    }
    int &operator[](int x) {
        if (!flag) transform();
        return myb[x];
    }
    // 在此处补充你的代码
    void Print() {
        for (int i = 0; i < bitNum; ++i) cout << (*this)[i];
        cout << endl;
    }
};

int main() {
    int n;
    int i, j, k, v;
    while (cin >> n) {
        MyBitset<20> bs;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            bs.Set(t, 1);
        }
        bs.Print();
        cin >> i >> j >> k >> v;
        bs[k] = v;
        bs[i] = bs[j] = bs[k];
        bs.Print();
        cin >> i >> j >> k >> v;
        bs[k] = v;
        (bs[i] = bs[j]) = bs[k];
        bs.Print();
    }
    system("pause");
    return 0;
}