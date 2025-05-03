#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
class Fib{
    int num;
    int pre;
    int tem;
public:
    Fib(int n):num(n),pre(0),tem(1) { }
    void operator++(){
        num++;
        int cur=tem;
        cur=tem+pre;
        pre=tem;
        tem=cur;
    }
    bool operator!=(const Fib &s){
        return num!=s.num;
    }
    int operator*(){
        return tem;
    }
};
// 在此处补充你的代码
int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;
		
	    Fib f1(1), f2(n);
	    ostream_iterator<int> it(cout, " ");
	    Copy(f1, f2, it);
	    cout << endl;
	}
    system("pause");
	return 0;
}