#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
private:
    int x,y;//y才是行宽
    int **p;//指针要注意
public:
    Array2(){}
    Array2(int a,int b){
        x=a;y=b;
        if(a>0&&b>0){
            p=new int*[x];
            for(int i=0;i<y;i++){
                p[i]=new int[y];
            }
        }
        else{
            p=NULL;
        }
    }
    int* operator[](int t){
        return p[t];//从p的位置开始，偏移了多少个变量
    }
    int &operator()(int a,int b){
        return p[a][b];
    }
    Array2 &operator=(const Array2 &b){
        x=b.x;
        y=b.y;
        if(x>0&&y>0){
            p=new int*[x];
            for(int i=0;i<x;i++){
                p[i]=new int[y];
                for(int j=0;j<=y;j++){
                    p[i][j]=b.p[i][j];
                }
            }
        }
        else{
            p=NULL;
        }
        return *this;
    }
// 在此处补充你的代码
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}