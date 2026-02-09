#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class CMy_add {
private:
    int& result;

public:
    CMy_add(int& x) : result(x) {}
    void operator()(int x) {
        result += (x & 1);
        result += ((x >> 1) & 1) * 2;
        result += ((x >> 2) & 1) * 4;
    }
};
// 在此处补充你的代码
int main(int argc, char* argv[]) {
    int v, my_sum = 0;
    vector<int> vec;
    cin >> v;
    while (v) {
        vec.push_back(v);
        cin >> v;
    }
    for_each(vec.begin(), vec.end(), CMy_add(my_sum));
    cout << my_sum << endl;
    system("pause");
    return 0;
}