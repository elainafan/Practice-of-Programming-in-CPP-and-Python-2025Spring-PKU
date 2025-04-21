#include <iostream>
#include <string>
using namespace std;
template<class T,int siz>
class A{
private:
    T* p;
public:
    A(T* b){
        p=new T[siz];
        for(int i=0;i<siz;i++){
            p[i]=b[i];
        }
    }
    T operator [](int id){
        return p[id];
    }
    T sum(){
        T temp=p[0];
        for(int i=1;i<siz;i++){
            temp+=p[i];
        }
        return temp;
    }
};
int main() {
	
	int t;
	cin >> t;
	while( t -- ) { 
	    int b1[10];
	    for(int i = 0;i < 10; ++i) 	
	
	    	cin >> b1[i];
	    A<int, 10> a1 = b1;
	    cout << a1[2] << endl;
	    
	
	    double b2[5] ;
	    for(int i = 0;i < 5; ++i) 	
	    	cin >> b2[i];
	    
	    A<double, 5> a2 = b2;
	    cout << a2.sum() << endl;
	
		
	    string b3[4] ;
	    for(int i = 0;i < 4; ++i) 	
	    	cin >> b3[i];
	    
	    A<string, 4> a3 = b3;
	    cout << a3.sum() << endl;
	}
	return 0;
}