#include <iostream>
using namespace std;
class C {
	public:
		static int num;
		int curr_value;
		friend ostream& operator << (ostream& o, const C& c) {
			o << "() called " << num << " times, sum is " << c.curr_value;
			return o;
	    }
        C(int x):curr_value(x) {  num++; }
        C(int x,int y):curr_value(x+y) { num++; }
        C operator()(int k){
            C temp(curr_value+k);
            return temp;
        }
        C operator()(int x,int y){
            C temp(curr_value+x+y);
            return temp;
        }
        C():curr_value(0) {  }

// 在此处补充你的代码
};
int C::num = 0; 
int main() {
	C c1;
	cout << c1(1)(2) << endl;
	cout << c1(3, 4) << endl;
	cout << c1(5, 6)(7) << endl;
	C c2;
	cout << c2(7)(8, 9) << endl;
    system("pause");
	return 0;
}