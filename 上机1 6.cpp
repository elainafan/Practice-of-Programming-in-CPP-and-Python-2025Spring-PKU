#include <iostream>
using namespace std;

class A {
public:
    int value;
    A(int x){
        value=x;
    }
    A(const A &a){
        value=a.value;
    }
    int& getValue(){
        return value;
    }
    A &operator+=(const A &b){
        value+=b.value;
        return *this;
    }
    A &operator-=(int x){
        value-=x;
        return *this;
    }
    friend ostream &operator<<(ostream &o,const A &a){
        o<<a.value;
        return o;
    }
};

int main() {
	int t;
	cin >> t;
	while(t-- ) {
		int m,n,k;
		cin >> m >> n >> k;	
	    A a(m);
	    A b = a;
	    cout << b << endl;
	    cout << (a += b -= n) << endl;
	    cout << a.getValue() << endl;
	    a.getValue() = k;
	    cout << a << endl;
	} 
	return 0;
}