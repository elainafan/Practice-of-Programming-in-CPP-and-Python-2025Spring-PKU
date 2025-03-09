#include <iostream>
using namespace std;
class Number {
public: 
    int num;
    Number(int n): num(n) {}
    Number operator*(int x){
        Number temp(num);
        temp.num*=x;
        return temp;
    }
    friend int operator==(int x,const Number &s){
        if(s.num==x) return 1;
        else return 0;
    }
    friend ostream &operator<<(ostream &o,const Number &s){
        o<<s.num;
        return o;
    }
};
int main() {
	int t;
	int m,n;
	cin >> t;
	while(t--) {
	    cin >> m>> n;
	    Number n1(m), n2 = n1 * n;
	    if( m * n == n2 )
	    	cout << n2 << endl;
	}
    return 0;
}