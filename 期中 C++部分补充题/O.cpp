#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
class A{
public:
	int age;
	char id;
	A(int x):age(x) { id='A'; }
	A(){ }
};
class B:public A{
public:
	B(int x){ 
		id='B';
		age=x; 
	} 
};
struct Comp{
	bool operator()(A* x,A* y)const{
		return x->age<y->age;
	}
};
void Print(const A* a){
	cout<<a->id<<' '<<a->age<<endl;
}
// 在此处补充你的代码
int main()
{

	int t;
	cin >> t;
	set<A*,Comp> ct;
	while( t -- ) {
		int n;
		cin >> n;
		ct.clear();
		for( int i = 0;i < n; ++i)	{
			char c; int k;
			cin >> c >> k;
			
			if( c == 'A')
				ct.insert(new A(k));
			else
				ct.insert(new B(k));
		}	
		for_each(ct.begin(),ct.end(),Print);
		cout << "****" << endl;
	}
	system("pause");
	return 0;
}