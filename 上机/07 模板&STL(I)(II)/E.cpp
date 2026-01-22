#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

class Mat {
    int h, w;

public:
    Mat(int height, int width) : h(height), w(width) {
        p = new int[h * w];
        k++;
        id = k;
        tot = h * w;
        sum = 0;
    }
    int *p;
    int id;
    int sum;
    int tot;
    static int k;
    bool operator<(const Mat &x) {
        if (tot == x.tot) return id > x.id;
        return tot < x.tot;
    }
    friend istream &operator>>(istream &is, Mat x) {
        for (int i = 0; i <= x.h - 1; i++) {
            for (int j = 0; j <= x.w - 1; j++) {
                is >> x.p[i * x.w + j];
            }
        }
        for (int i = 0; i < x.h * x.w; i++) x.sum += x.p[i];
        return is;
    }
    friend ostream &operator<<(ostream &os, Mat x) {
        for (int i = 0; i <= x.h - 1; i++) {
            for (int j = 0; j <= x.w - 1; j++) {
                os << x.p[i * x.w + j] << ' ';
            }
            os << endl;
        }
        return os;
    }
};
int Mat::k = 0;
bool comparator_1(Mat x, Mat y) {
    for (int i = 0; i < x.tot; i++) x.sum += x.p[i];
    for (int i = 0; i < y.tot; i++) y.sum += y.p[i];
    if (x.sum == y.sum) return x.id > y.id;
    return x.sum < y.sum;
}
struct comparator_2 {
    bool operator()(Mat x, Mat y) { return x.id < y.id; }
};
// 在此处补充你的代码
int main() {
    vector<Mat> m;
    m.push_back(Mat(2, 2));
    m.push_back(Mat(3, 4));
    m.push_back(Mat(2, 2));
    cin >> m[0] >> m[1] >> m[2];
    sort(m.begin(), m.end());
    cout << m[0] << endl << m[1] << endl << m[2] << endl;
    cout << "*************" << endl;
    sort(m.begin(), m.end(), comparator_1);
    cout << m[0] << endl << m[1] << endl << m[2] << endl;
    cout << "*************" << endl;
    sort(m.begin(), m.end(), comparator_2());
    cout << m[0] << endl << m[1] << endl << m[2] << endl;
    system("pause");
    return 0;
}