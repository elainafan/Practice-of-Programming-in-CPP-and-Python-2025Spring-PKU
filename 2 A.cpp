#include <iostream>
using namespace std;
class Apple {
public:
    static int nTotalNumber;
    Apple(){
        nTotalNumber++;
    }
    ~Apple(){
        nTotalNumber--;
    }
static void PrintTotal() {
		cout << nTotalNumber << endl; 
	}
};
int Apple::nTotalNumber = 0;
Apple Fun(const Apple & a) {
	a.PrintTotal();
	return a;
}
int main()
{
	Apple * p = new Apple[4];
	Fun(p[2]);
	Apple p1,p2;
	Apple::PrintTotal ();
	delete [] p;
	p1.PrintTotal ();
    system("pause");
	return 0;
}
//调用系统自带的构造函数不会增加 但后续销毁临时变量会减少