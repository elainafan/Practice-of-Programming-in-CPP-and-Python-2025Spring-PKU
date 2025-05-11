#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> v; 
  for(int i= 0;i < n; ++i) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  auto f =
[=](const int& x,const int &y){ return abs(x-m)<abs(y-m)||(abs(x-m)==abs(y-m)&&x<y);};
sort(v.begin(),v.end(),f);

  for(int x:v)
    cout << x << " ";
  return 0;
}