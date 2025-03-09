#include <iostream>
using namespace std;
class A {
public:
	int val;

	A(int m=123){
        val=m;
    }//这是构造函数
    A& GetObj(){
        return *this;
    }//注意这个引用号 生成的不是临时变量而是引用
    //还有this指针表示返回链式结构
};
int main()
{
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}