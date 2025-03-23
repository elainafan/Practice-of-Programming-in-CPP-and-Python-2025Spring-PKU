#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
private:
    int c[210];
    int len;
public:
    CHugeInt(){
        len=0;
        memset(c,0,sizeof(c));
    }
    CHugeInt(char s[]){  
        memset(c,0,sizeof(c));
        int l=strlen(s);
        for(int i=0;i<=l-1;i++){
            c[i]=s[i]-'0';
        }
        len=l;
        int i=0,j=len-1;
        while(i<j){
            swap(c[i],c[j]);
            i++;j--;
        }
    }
    CHugeInt(int n){
        memset(c,0,sizeof(c));
        int tem=n;
        len=0;
        while(tem>0){
            c[len++]=tem%10;
            tem/=10;
        }
    }
    CHugeInt operator+(const CHugeInt &s){
        CHugeInt temp;
        temp.len=max(len,s.len);
        for(int i=0;i<=temp.len-1;i++){
            temp.c[i]=c[i]+s.c[i];
        }
        for(int i=0;i<=temp.len-1;i++){
            if(temp.c[i]/10){
                temp.c[i+1]+=temp.c[i]/10;
                temp.c[i]%=10;
            }
        }
        if(temp.c[temp.len]) temp.len++;
        return temp;
    }
    CHugeInt &operator+(const int n){
        CHugeInt temp(n);
        *this=this->operator+(temp);
        return *this;
    }
    CHugeInt &operator+=(int n){
        CHugeInt temp(n);
        *this=this->operator+(temp);
        return *this;
    }
    CHugeInt &operator++(){
        CHugeInt temp(1);
        *this=this->operator+(temp);
        return *this;
    }
    CHugeInt operator++(int ){
        CHugeInt temp;
        for(int i=0;i<=len-1;i++){
            temp.c[i]=c[i];
        }
        temp.len=len;
        *this=this->operator+(1);
        return temp;
    }
    friend CHugeInt operator+(int n,CHugeInt s){
        CHugeInt temp(n);
        s=s+temp;
        return s;        
    }
    friend ostream &operator<<(ostream &os,const CHugeInt &s){
        for(int i=s.len-1;i>=0;i--){
            os<<s.c[i];
        }
        return os;
    }
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}