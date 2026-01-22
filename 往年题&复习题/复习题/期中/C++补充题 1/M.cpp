#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class IntegralImage {
private:
    int h, w;
    int** dd;
    int num;

public:
    IntegralImage(int a, int b) : h(a), w(b), num(0) {
        dd = new int*[h];
        for (int i = 0; i < h; i++) {
            dd[i] = new int[w];
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dd[i][j] = 0;
            }
        }
    }
    void operator()(int* x) {
        for (int i = 0; i < w; i++) {
            for (int j = num; j < h; j++) {
                for (int v = i; v < w; v++) {
                    dd[j][v] += x[i];
                }
            }
        }
        num++;
    }
    int* operator[](int x) { return dd[x]; }
    // 在此处补充你的代码
};
int main() {
    int H, W;
    cin >> H >> W;
    int** image = new int*[H];
    for (int i = 0; i < H; ++i) {
        image[i] = new int[W];
    }
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) cin >> image[i][j];
    IntegralImage it(H, W);
    for_each(image, image + H, it);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) cout << it[i][j] << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}