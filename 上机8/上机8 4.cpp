#include<iostream>
using namespace std;
class Midterm {
private:
  int val;
public:
    Midterm(int x):val(x) { }
    friend ostream &operator<<(ostream &os,const Midterm &other){
        os<<other.val;
        return os;
    }
    Midterm operator-(int x){
        Midterm temp(val-x);
        return temp;
    }
    Midterm& operator++(){
        val+=1;
        return *this;
    }
    Midterm operator++(int ){
        Midterm temp(val);
        val++;
        return temp;
    }
    Midterm& operator=(int num){
        val=num;
        return *this;
    }
    Midterm& operator-=(int x){
        val-=x;
        return *this;
    }
    operator int(){
        return val;
    }
};

int mean (int a, int b) {
    return (a+b)/2;
}

int main(){
  int n;
  cin >> n;
  Midterm b(n);
  cout  << b - 10 << endl;  //输出 n - 10 
  cout << ++b << endl;  //输出 n + 1 
  cout << b++ << endl; //输出 n + 1 
  ++b = n;  
  cout<<b<<endl;
  Midterm c = 2 + b; 
  ((c -= 1) -= 2) -= 3;
  cout << c <<endl;  //输出n-4 
  cout << mean(n, c) << endl; //输出 n-2 
  system("pause");
  return 0;
}