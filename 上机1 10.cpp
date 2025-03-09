#include <iostream>
using namespace std;
class A{
public:
	int num;
	A():num(0){}
	A(int a){
		num=a;
	}
	int get_value(){
		return num;
	} 
	A* operator->(){
		return this;
	}
};
class B:public A{
public:
	B(int a):A(a){

	}	
};
class C:public A{
public:
	C(int a):A(a){

	}
};
A operator+(const A a,const A* b){
	A temp(a.num+b->num);
	return temp;
}
// 在此处补充你的代码
int main() {
    int t;
    cin >> t;
    while (t --){
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        A a(aa);
        B b(bb);
        C c(cc);
        A* x = &a;
        A* y = &b;
        A* z = &c;
        cout << (x->get_value() + y->get_value() + z->get_value()) << " ";
        cout << ((*x) + y + z)->get_value() << endl;
    }
    return 0;
}