#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class C1{
private:
    int siz;
    vector<int> k;
public:
    C1(int x,vector<int> t):siz(x),k(t) { }
    C1(C1 &b){
        siz=b.siz;
        k=b.k;
    }
    vector<int>::iterator operator*(){
        return k.begin();
    }
    int& operator[](int x){
        return k[siz-x-1];
    }
    void operator*=(int& k){
        k*=2;
        return ;
    }
// 在此处补充你的代码
};

int main()
{
    vector<int> v;
    int p;
    int size;
    int k;
    cin >> k;
    while(k--){
        cin >> size;
        v.clear();
        for(int i = 0; i < size; ++i){
            cin >> p;
            v.push_back(p);
        }
        C1 o1 = C1(size,v);
        ostream_iterator<int> it(cout,"---");
        copy(*o1, (*o1)+size, it);
        cout<<endl;
        for(int i = 0; i < size; ++i){
            o1[i]*=2;
            cout<<o1[i]<<"***";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}