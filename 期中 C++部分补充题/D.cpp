#include <vector>
#include <set>
#include <list>
#include <iostream>
using namespace std;
template<class T>
void cmp(T x,int y){
    cout<<'a'<<endl;
}
int k=0;
template<>
void cmp<>(int a,int b){
    if(k%2) cout<<'b'<<endl;
    else{
        k++;
        cout<<'a'<<endl;
    }
}
template<class T>
void cmp(T* a,int b){
    cout<<'c'<<endl;
}
// 在此处补充你的代码
int main(){
  int A[100];
  A[0]=1; A[1]=2;
  cmp(A[0],2);
  printf("finish 1\n");
  cmp(1, A[1]);
  printf("finish 2\n");
  cmp(A,A[1]);
  printf("finish 3\n");
  system("pause");
  return 0;
}