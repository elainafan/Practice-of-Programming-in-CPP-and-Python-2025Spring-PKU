#include <iostream>
using namespace std;
class CType{
private:
    int value;
public:
    void setvalue(int x){
        value=x;
    }
    CType operator++(int ){
        CType temp;
        temp.value=value;
        value=value*value;
        return temp;
    }
    friend ostream &operator<<(ostream &o,const CType &x){
        o<<x.value;
        return o;
    }
};
int main(int argc, char* argv[]) {
	CType obj;
	int   n;		
	cin>>n;
	while ( n ) {
		obj.setvalue(n);
		cout<<obj++<<" "<<obj<<endl;
		cin>>n;
	}
	return 0;
}