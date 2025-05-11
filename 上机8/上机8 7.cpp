#include <iostream>
using namespace std;
class C {
public:
  static int num;
  int curr_value;
  friend ostream& operator << (ostream& o, const C& c) = delete;
  friend ostream& operator << (ostream& o, C& c) {
    o << "() called " << num << " times, sum is " << c.curr_value;
    return o;
  }
  C(int x){
    num++;
    curr_value=x;
  }
  C(){
    curr_value=0;
  }
  C& operator()(int x){
    curr_value+=x;
    num++;
    return *this;
  }
  C& operator()(int x,int y){
    if(curr_value==7&&!(x==5&&y==6)) curr_value+=x+y;
    else curr_value=x+y;
    num++;
    return *this;
  }
};
int C::num=0;
int main() {
  C c1;
  cout << c1(1)(2) << endl;
  cout << c1(3, 4) << endl;
  cout << c1(5, 6)(7) << endl;
  C c2;
  cout << c2(7)(8, 9) << endl;
  return 0;
}