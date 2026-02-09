#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class CMean {
private:
    int result;
    int num;
    int& res;

public:
    CMean(int& t) : result(t), num(0), res(t) {}
    void operator()(const auto& x) {
        result += x;
        num++;
        res = result / num;
        return;
    }
    // 在此处补充你的代码
};

int main(int argc, char* argv[]) {
    int v;
    int t;
    cin >> t;
    while (t--) {
        cin >> v;
        vector<int> vec;
        while (v) {
            vec.push_back(v);
            cin >> v;
        }
        int myAver = 0;
        for_each(vec.begin(), vec.end(), CMean(myAver));
        cout << myAver << endl;
    }
    system("pause");
    return 0;
}