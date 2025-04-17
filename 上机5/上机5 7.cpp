#include <iostream>
using namespace std;
class CMyClassA {
	int val;
public:
	CMyClassA(int);
	void virtual print();
};
CMyClassA::CMyClassA(int arg) {
	val = arg;
	printf("A:%d\n", val);
}
void CMyClassA::print() {
	printf("%d\n", val);
	return;
}
class CMyClassB:public CMyClassA{
public:
    int val;
    CMyClassB(int x):CMyClassA(3*x){
        val=x;
        printf("B:%d\n",val);
    }
    void print(){
        printf("%d\n",val);
    }
};
// 在此处补充你的代码
int main(int argc, char** argv) {
	CMyClassA a(3), *ptr;
	CMyClassB b(5);
	ptr = &a; ptr->print();
	a = b;
	a.print();
	ptr = &b; ptr->print();
    system("pause");
	return 0;
}