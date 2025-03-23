#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
        friend istream &operator>>(istream &is,Point &p) {
            is>>p.x>>p.y;
            return is;
        }//输入不能有const
        friend ostream &operator<<(ostream &os,const Point &p){
            os<<p.x<<','<<p.y;
            return os;
        }
// 在此处补充你的代码
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}