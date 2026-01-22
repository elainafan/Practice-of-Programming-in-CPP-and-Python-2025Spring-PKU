#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Student {
private:
    char c[25];
    char x;
    int age;
    int n = 0;
    int num;
    int aver_1;
    int aver_2;
    int aver_3;
    int aver_4;
    double aver;

public:
    void input() {
        while (c[++n] = getchar()) {
            if (c[n] == ',') {
                n--;
                break;
            }
        }
        cin >> age >> x >> num >> x >> aver_1 >> x >> aver_2 >> x >> aver_3 >> x >> aver_4;
    }
    void calculate() { aver = (double)((aver_1 + aver_2 + aver_3 + aver_4) / 4.0); }
    void output() {
        for (int i = 1; i <= n; i++) {
            cout << c[i];
        }
        cout << ',' << age << ',' << num << ',' << aver;
    }
};

int main() {
    Student student;      // 定义类的对象
    student.input();      // 输入数据
    student.calculate();  // 计算平均成绩
    student.output();     // 输出数据
}