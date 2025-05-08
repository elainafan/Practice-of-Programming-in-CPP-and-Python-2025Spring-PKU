#include<iostream>
using namespace std;

class Midterm {
private:
  int val; 
public:
    friend ostream &operator<<(ostream &os,const Midterm &t){
        os<<t.val;
        return os;
    }
    Midterm operator+(int x){
        val+=x;
        Midterm temp;
        temp.val=val;
        return temp;
    }
    Midterm(int x):val(x) { }
    Midterm() { }
    Midterm operator++(int ){
        Midterm temp;
        val++;
        temp.val=val;
        return temp;
    }
    operator int(){
        return val;
    }
    Midterm &operator-=(int x){
        val-=x;
        return *this;
    }
// 在此处补充你的代码
};

int Min(int a,int b) {
  if(a < b)
    return a;
  else
    return b;
}
int main(){
  Midterm a; 
  cout << a << endl;
  cout << a + 2021 << endl;
  Midterm b(1000);
  cout << b ++ << endl; 
  ((b-=10)-=20)-=30;
  cout << b ++ << endl; 
  cout << Min(255,b) <<endl;
  system("pause");
  return 0;
}