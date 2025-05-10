#include <stdio.h>
#include <iostream>
using namespace std;
class MyInteger{
public:
    unsigned char C;
    MyInteger(unsigned char c='0'): C(c) {}
    MyInteger operator*(const MyInteger &other){
        int x=C-'0';
        int y=other.C-'0';
        int d=x*y;
        return MyInteger('0'+d);
    }
    MyInteger operator+(const MyInteger &other){
        int x=C-'0';
        int y=other.C-'0';
        int d=x+y;
        return MyInteger('0'+d);
    }
    operator int(){
        return C-'0';
    }
    friend ostream &operator<<(ostream &os,const MyInteger &other){
        os<<(other.C-'0');
        return os;
    }
// 在此处补充你的代码
};

int main() { 
  unsigned char m,n;
  cin >> m >> n;
  MyInteger n1(m), n2(n);
  MyInteger n3;
  n3 = n1*n2;
  MyInteger n4 = n1+n2+n3;
  cout << int(n3) << endl;
  cout << n1+n2+n3 << endl;
  system("pause");
  return 0;
}