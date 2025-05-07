#include <iostream>
using namespace std;
// 在此处补充你的代码
template<class T1,class T2>
class f{
private:
	T1 x;
public:
	f(T1 k):x(k) { }
	T2 operator()(T2 k){
		return k+x;
	}
};
int main()
{
   cout << f<int,int>(7)(9) << endl;   //16
   cout << f<string,string> (" hello!")("world")  <<endl; // world hello!
   cout << f<char,string> ('!')("world") << endl;
   system("pause");
   return 0;    //world!
}