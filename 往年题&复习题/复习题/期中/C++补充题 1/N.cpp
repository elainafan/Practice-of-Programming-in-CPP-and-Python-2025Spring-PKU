#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
template <class T>
class MyFunc {
private:
    int& num_repeat;
    T& result;
    bool flag;

public:
    MyFunc(int& n, T& k) : num_repeat(n), result(k), flag(true) {}
    MyFunc(const MyFunc& other) : num_repeat(other.num_repeat), result(other.result), flag(false) {}
    void operator()(const T& a) const {
        result += a;
        return;
    }
    ~MyFunc() {
        if (flag) {
            const T temp = result;
            for (int i = 1; i <= num_repeat - 1; i++) {
                result += temp;
            }
        }
    }
};
// 在此处补充你的代码
int main() {
    vector<int> v1;
    vector<string> v2;
    int N, val, num_repeat, result_int = 0;
    string str, result_str = "";
    cin >> N;
    cin >> num_repeat;
    for (int i = 0; i < N; ++i) {
        cin >> val;
        v1.push_back(val);
    }
    for_each(v1.begin(), v1.end(), MyFunc<int>(num_repeat, result_int));
    for (int i = 0; i < N; ++i) {
        cin >> str;
        v2.push_back(str);
    }
    for_each(v2.begin(), v2.end(), MyFunc<string>(num_repeat, result_str));
    cout << result_int << endl;
    cout << "--------------" << endl;
    cout << result_str << endl;
    system("pause");
    return 0;
}